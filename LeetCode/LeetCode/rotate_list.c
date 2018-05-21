#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

static struct ListNode* rotateRight() {
    if(head == NULL || k <= 0) {
        return head;
    }
    
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode *prev = &dummy;
    struct ListNode *last = &dummy;
    struct ListNode *p = head;
    int count = k;
    while(k>0) {
        if(p == NULL){
            int length = count - k;
        }
    }
    
}

