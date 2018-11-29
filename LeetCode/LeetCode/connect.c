#include<stdio.h>
#include<stdlib.h>

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
};

static void connect(struct TreeLinkNode *root) {
    if(root == NULL) {
        return;
    }

    struct TreeLinkNode *head = root;
    while(head->left != NULL) {
        struct TreeLinkNode *p;
        for(p = head; p != NULL; p = p->next) {
            p->left->next = p->right; 
            p->right->next = p->next == NULL ? NULL : p->next->left; 
        }
        head = head->left;
    }
}
