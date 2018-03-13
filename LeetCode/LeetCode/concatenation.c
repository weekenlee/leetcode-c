#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//http://ilinuxkernel.com/?p=1062
//参考自linux内核
//用于在已知结构体里面成员member和该成员指针ptr（就是地址）和结构体类型type, 返回该成员所在的结构体的指针（就是地址）
//实现该方法可以分三步：
//0 算出a.node在a里面的偏移，可以通过将零地址强制转换成struct word_node格式, (struct word_node *)0, 那么((struct word_node *)0)->node 即是偏移大小
//1 已知a.node地址和在a里面的偏移，即可通过a.node 地址减去偏移得到a的地址, (char *)ptr - ((struct word_node *)0)->node
//2 最后将得到的地址强制 转换成struct word_node 格式, (struct word_node *)((char *)ptr - ((struct word_node *)0)->node) 即为所求的指针
#define container_of(ptr, type, member) \
	((type*)((char*)(ptr) - (size_t)&(((type*)0)->member)))

#define list_entry(ptr, type , member) \
	container_of(ptr, type, member)

#define hlist_for_each(pos, head) \
	for (pos = (head)->first; pos; pos=pos->next)

struct hlist_node;

struct hlist_head {
	struct hlist_node *first;
};

struct hlist_node {
	struct hlist_node *next, **pprev;
};

static inline void  INIT_HLIST_HEAD(struct hlist_head *h) {
	h->first = NULL;
}

static inline int hlist_empty(struct hlist_head *h) {
	return !h->first;
}

static inline void hlist_add_head(struct hlist_node *n, struct hlist_head *h) {
	if (h->first != NULL) {
		h->first->pprev = &n->next;
	}
	n->next = h->first;
	n->pprev = &h->first;
	h->first = n;
}

struct word_node {
	struct hlist_node node;
	char *word;
	int index;
};

static inline int BKDRHash(char *s, size_t size)
{
	int seed = 131;
	unsigned long hash = 0;
	while (*s != '\0') {
		hash = hash * seed + *s++;
	}
	return hash % size;
}

static int find(char *word, struct hlist_head *heads, int size) {
	int hash = BKDRHash(word, size);
	struct hlist_node *pos;
	hlist_for_each(pos, &heads[hash]) {
		struct word_node *wn = list_entry(pos, struct word_node, node);
		if (!strcmp(wn->word, word)) {
			return wn->index;
		}
	}
	return -1;
}

static void add(char** words, int index, struct hlist_head *heads, int size, int *freqs)
{
	int hash = BKDRHash(words[index], size);
	struct hlist_node *pos;
	struct word_node *wn;
	hlist_for_each(pos, &heads[hash]) {
		wn = list_entry(pos, struct word_node, node);
		if (!strcmp(wn->word, words[index])) {
			freqs[wn->index]++;
			return;
		}
	}
	wn = malloc(sizeof(*wn));
	wn->word = words[index];
	wn->index = index;
	hlist_add_head(&wn->node, &heads[hash]);
	freqs[wn->index]++;
}


static int *findSubstring(char *s, char **words, int wordsSize, int *returnSize)
{
	if (*s == '\0' || wordsSize == 0) {
		*returnSize = 0;
		return NULL;
	}
	int i, j, cap = 10000, count = 0;
	int hash_size = wordsSize;
	struct hlist_head *heads = malloc(hash_size * sizeof(*heads));
	for (i = 0; i < hash_size; i++) {
		INIT_HLIST_HEAD(&heads[i]);
	}

	int *freqs = malloc(wordsSize * sizeof(int));
	memset(freqs, 0, wordsSize * sizeof(int));

	for (i = 0; i < wordsSize; i++) {
		add(words, i, heads, hash_size, freqs);
	}

	int len = strlen(words[0]);
	int length = len * wordsSize - 1;
	char *word = malloc(len + 1);
	word[len] = '\0';
	int *indexes = malloc(cap * sizeof(int));
	for (i = 0; s[i] != '\0'; i++) {
		memcpy(word, s + i, len);
		indexes[i] = find(word, heads, hash_size);
	}

	int *results = malloc(cap * sizeof(int));
	int *fqs = malloc(wordsSize * sizeof(int));
	for (i = 0; s[i + length] != '\0'; i++) {
		memset(fqs, 0, wordsSize * sizeof(int));
		for (j = 0; j < wordsSize; j++) {
			int index = indexes[i + j * len];
			if (index<0 || ++fqs[index] > freqs[index]) {
				break;
			}
		}
		if (j == wordsSize) {
			results[count++] = i;
		}
	}

	*returnSize = count;
	return results;
}

int main(int argc, char **argv)
{
	int i, count = 0;
	char *words[2] = { "foo", "bar"};
	int *results = findSubstring("barfoothefoobarman", words, 2, &count);
	for (i = 0; i < count; i++) {
		printf("%d ", results[i]);
	}
	printf("\n");
	getchar();
	return 0;
}