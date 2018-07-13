#include<stdio.h>
#include<stdlib.h>

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - (size_t)&(((type *)0)->member)))

#define list_entry(ptr, type, member) \
    container_of(ptr, type, member)

#define hlist_for_each(pos, head) \
    for(pos = (head)->first; pos; pos = pos->next)

struct hlist_node;

struct hlist_head {
    struct hlist_node *first;
};

struct hlist_node {
    struct hlist_node *next, **pprev;
};

static inline void INIT_HLIST_HEAD(struct hlist_head *h)
{
    h->first = NULL;
}

static inline int hlist_empty(struct hlist_head *h) {
    return !h->first;
}

static inline void hlist_add_head(struct hlist_node *n, struct hlist_head *h) 
{
    if ( h->first != NULL) {
        h->first->pprev = &n->next;
    }
    n->next = h->first;
    n->pprev = &h->first;
    h->first = n;
}

static inline void hlist_del(struct hlist_node *n)
{
    struct hlist_node *next = n->next;
    struct hlist_node **pprev = n->pprev;
    *pprev = next;
    if(next != NULL) {
        next->pprev = pprev;
    }
}

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct order_node {
    struct hlist_node node;
    int val;
    int index;
};

static int find(int num, int size, struct hlist_head *heads)
{
    struct hlist_node *p; 
}
