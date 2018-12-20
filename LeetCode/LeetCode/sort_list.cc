#include <cstddef>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
    void moveNode(ListNode **destRef, ListNode **sourceRef) {
        ListNode *newNode = *sourceRef;
        *sourceRef = newNode->next;
        newNode->next = *destRef;
        *destRef = newNode;
    }

    ListNode *sortedMerge(ListNode *a, ListNode *b) {
        ListNode *ret = nullptr, **lastPtrRef = &ret;
        for(; a&&b; lastPtrRef = &((*lastPtrRef)->next)) {
            if(a->val <= b->val) {
                moveNode(lastPtrRef, &a);
            }else {
                moveNode(lastPtrRef, &b);
            }
        }
        *lastPtrRef = a ? a : b;
        return ret;
    }

    void frontBackSplit(ListNode *source, ListNode **frontRef, ListNode **backRef) {
        if(source == nullptr || source->next == nullptr) {
            *frontRef = source;
            *backRef = nullptr;
        }else {
            ListNode *slow = source,
                     *fast = source->next;
            while(fast != nullptr) {
                fast = fast->next;
                if(fast != nullptr) {
                    slow = slow->next;
                    fast = fast->next;
                }
            }
            *frontRef = source;
            *backRef = slow->next;
            slow->next = nullptr;
        }
    }

    void mergeSort(ListNode **headRef) {
        ListNode *head = *headRef, *front, *back;
        if(head == nullptr || head->next == nullptr) {
            return ;
        }
        frontBackSplit(head, &front, &back);
        printList(front);
        printList(back);
        mergeSort(&front);
        mergeSort(&back);
        *headRef = sortedMerge(front, back);
    }

    void printList(ListNode *head) {
        for(ListNode *cur = head; cur; cur = cur->next) {
            cout << cur->val <<"->";
        }
        cout << "\bb "<<endl;
    }

    public:
    ListNode *sortList(ListNode *head) {
        mergeSort(&head);
        return head;
    }
};

#include <iostream>
#include <initializer_list>
using namespace std;

ListNode *create_linkedlist(std::initializer_list<int> lst) {
    auto iter = lst.begin();
    ListNode *head = lst.size() ? new ListNode(*iter++) : nullptr;
    for(ListNode *cur = head; iter != lst.end(); cur = cur->next) {
        cur->next = new ListNode(*iter++);
    }
    return head;
}

void clear(ListNode *head) {
    while(head ) {
        ListNode *del = head;
        head = head -> next;
        delete del;
    }
}

void printList(ListNode *head) {
    for(ListNode *cur = head; cur; cur = cur->next) {
        cout << cur->val <<"->";
    }
    cout << "\bb "<<endl;
}

int main() 
{
    Solution s;
    ListNode *a = create_linkedlist({4,3,5,1,9});
    ListNode *ret = s.sortList(a);
    printList(ret);
    clear(ret);
}
