#include<stdio.h>
#include<stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

static struct ListNode* mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{
	struct ListNode dummy, *tail = &dummy;
	dummy.next = NULL;

	while (l1 != NULL || l2 != NULL) {
		struct ListNode *node = malloc(sizeof(*node));
		node->next = NULL;
		tail->next = node;
		tail = node;
		if (l1 != NULL) {
			if (l2 != NULL) {
				if (l1->val < l2->val) {
					node->val = l1->val;
					l1 = l1->next;
				}
				else {
					node->val = l2->val;
					l2 = l2->next;
				}
			}
			else {
				node->val = l1->val;
				l1 = l1->next;
			}
		}
		else {
			node->val = l2->val;
			l2 = l2->next;
		}
	}
	return dummy.next;
}

static struct ListNode* mergeKLists(struct ListNode ** lists, int listsSize)
{
	if (listsSize == 0) {
		return NULL;
	}
	if (listsSize == 1) {
		return lists[0];
	}

	int i, index;
	struct ListNode dummy, *p, *prev;

	dummy.next = NULL;
	prev = &dummy;
	index = 0;
	while (index != -1) {
		int min = INT_MAX;
		index = -1;
		for (i = 0; i < listsSize; i++) {
			if (lists[i] != NULL && lists[i]->val < min) {
				min = lists[i]->val;
				index = i;
			}
		}

		if (index != -1) {
			p = malloc(sizeof(*p));
			p->val = min;
			p->next = NULL;
			prev->next = p;
			prev = p;
			lists[index] = lists[index]->next;
		}
	}

	return dummy.next;
}

static struct ListNode* swapPairs(struct ListNode *head)
{
	if (head == NULL) {
		return NULL;
	}

	struct ListNode dummy;
	dummy.next = head;

	struct ListNode *prev = &dummy;
	struct ListNode *p = dummy.next;
	struct ListNode *next = p->next;

	while (p != NULL && next != NULL) {
		prev->next = next;
		p->next = next->next;
		next->next = p;
		prev = p;
		p = p->next;
		if (p != NULL) {
			next = p->next;
		}
	}
	return dummy.next;
}

int main(int argc, char **argv)
{
	struct ListNode  l1;
	l1.val = 2;
	l1.next = NULL;
	struct ListNode  l2;
	l2.val = 1;
	l2.next = NULL;
	struct ListNode  * list = mergeTwoLists(&l1, &l2);
	while (list != NULL) {
		printf("%d ", list->val);
		list = list->next;
	}
	printf("\nend merge two list\n");



	int i, size;
	struct ListNode *p, *prev, *sorted, dummy1, dummy2, **lists;

	dummy1.next = NULL;
	prev = &dummy1;
	for (i = 0; i < 3; i++) {
		p = malloc(sizeof(*p));
		p->val = i * 2;
		p->next = NULL;
		prev->next = p;
		prev = p;
	}
	printf("list1 ");
	for (p = dummy1.next; p != NULL; p = p->next) {
		printf("%d ", p->val);
	}
	putchar('\n');

	dummy2.next = NULL;
	prev = &dummy2;
	for (i = 0; i < 5; i++) {
		p = malloc(sizeof(*p));
		p->val = i * 2 + 1;
		p->next = NULL;
		prev->next = p;
		prev = p;
	}
	printf("list2 ");
	for (p = dummy2.next; p != NULL; p = p->next) {
		printf("%d ", p->val);
	}
	putchar('\n');

	size = 2;
	lists = malloc(size * sizeof(struct ListNode *));
	lists[0] = dummy1.next;
	lists[1] = dummy2.next;
	sorted = mergeKLists(lists, size);
	printf("result ");
	for (p = sorted; p != NULL; p = p->next) {
		printf("%d ", p->val);
	}
	putchar('\n');

	list = swapPairs(sorted);
	printf("swap result ");
	for (p = list; p != NULL; p = p->next) {
		printf("%d ", p->val);
	}
	putchar('\n');


	char c = getchar();
	return 0;
}