#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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

static void add