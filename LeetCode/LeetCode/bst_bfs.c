#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BST_MAX_LEVEL 800

#define container_of(ptr, type, member) \
    ((type * )((char *)(ptr)- (sizer_t)&(((type *)0)->member)))

#define list_entry(ptr, type, member) \
    container_of(ptr, type, member)

#define list_first_entry(ptr, type, field) \
    list_entry((ptr)->next, type, field)

#define list_last_entry(ptr, type, field) \
    list_entry((ptr)->prev, type, field)

#define list_for_each(p, head) \
    for(p = (head)->next; p!=(head); p=p->next)

#define list_for_each_safe(p, n, head)\
    for(p = (head)->next, n = p->next; p!=(head); p = n, n = p->next)

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct list_head {
    struct list_head *next, *prev;
};

static inline void INIT_LIST_HEAD(struct list_head *list) {
    list->next = list->prev = list;
}
static inline int list_empty(const struct list_head *head) {
    return (head->next == head);
}

static inline void __list_add(struct list_head *new, struct list_head
        *prev, struct list_head *next) {
    next->prev = new;
    new->next = next;
    new->prev = prev;
    prev->next = new;
}

static inline void list_add(struct list_head *_new, struct list_head *head) {
    __list_add(_new, head, head->next);
}

static inline void list_add_tail(struct list_head *_new, struct list_head *head) {
    __list_add(_new, head->prev, head);
}

static inline void __list_del(struct list_head *entry) {
    entry->next->prev = entry->prev;
    entry->prev->next = entry->next;
}

static inline void list_del(struct list_head *entry) {
    __list_del(entry);
    entry->next = entry->prev = NULL;
}

struct bfs_node {
    struct TreeNode *node;
    struct list_head link;
};

static struct bfs_node *node_new(struct list_head *free_list,struct
        TreeNode *node) 
{
    struct bfs_node *new;
    if(list_empty(free_list)) {
        new = malloc(sizeof(*new));
    }else {
        new = list_first_entry(free_list, struct bfs_node, link);
        list_del(&new->link);
    }
    new->node = node;
    return new;
}
