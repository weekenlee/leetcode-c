#include <cstddef>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    ListNode *reverseList(ListNode *head) {
        ListNode *newHead = NULL;
        while( head) {
            ListNode *next = head->next;
            head->next = newHead;
            newHead = head;
            head = next;
        }
        return newHead;
    }

    ListNode *shuffleMerge(ListNode *a, ListNode *b) {
        ListNode *ret = NULL, **lastRef = &ret;
        while (a && b) {
            moveNode(lastRef, &a);
            lastRef = &((*lastRef)->next);
            moveNode(lastRef, &b);
            lastRef = &((*lastRef) ->next);
        }
        *lastRef = a ? a : b;
        return ret;
    }

    void moveNode(ListNode **destRef , ListNode **sourceRef ) {
        ListNode *newNode = *sourceRef;
        *sourceRef = newNode -> next;
        newNode->next = *destRef;
        *destRef = newNode;
    }

    public:
    void reorderList(ListNode *head) {
        if(head == NULL) return;
        ListNode *slow = head, *fast = head->next;
        while(fast) {
            fast = fast->next;
            if(fast) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        ListNode *back = reverseList(slow->next);
        slow->next = NULL;
        head = shuffleMerge(head, back);
    }
};

#include<iostream>
#include<initializer_list>

using namespace std;

ListNode *create_linkedlist(std::initializer_list<int> lst) {
    auto iter = lst.begin();
    ListNode *head = lst.size() ? new ListNode(*iter++) : nullptr;
    for(ListNode *cur = head; iter != lst.end(); cur = cur->next) {
        cur->next = new ListNode(*iter++);
    }
    return head;
}

void clear(ListNode *head ){
    while(head) {
        ListNode *del = head;
        head = head -> next;
        delete del;
    }
}

void printList(ListNode *head ) {
    for(ListNode *cur = head; cur; cur = cur -> next) {
        cout << cur->val << "->";
    }
    cout <<"\b\b " << endl;
}

int main()
{
    Solution s;
    ListNode *a = create_linkedlist({1,2,3,4,5,6,7,8,9});
    s.reorderList(a);
    printList(a);
    clear(a);
}
