#include<iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
    public:
        ListNode * deleteDuplicates(ListNode* head) {
            auto iter = head;
            while(iter) {
                auto runner = iter->next;
                while(runner && runner->val == iter->val) {
                    runner = runner->next;
                }

                iter->next = runner;
                iter = runner;
            }
            return head;
        }

        ListNode *deleterDuplicates2(ListNode *head) {
            ListNode dummy{0};
            auto prev = &dummy;
            while(head) {
                if(head->next && head->next->val == head->val) {
                    auto val = head->val;
                    while(head && head->val == val) {
                        head = head->next;
                    }
                    prev->next = head;
                } else {
                    prev ->next = head;
                    prev = head;
                    head = head->next;
                }
            }

            return dummy.next;
        }
};

int main(int argc, char **argv)
{
    int i;
    ListNode *head = NULL;
    ListNode *prev = NULL;
    ListNode *p;
    for (i = 0; i < argc - 1; ++i) {
        p = new ListNode(atoi(argv[i+1]));
        if(head == NULL) {
            head = p;
            prev = head;
        }else {
            prev->next = p;
            prev = p;
        }
    }

    p = Solution().deleteDuplicates(head);
    //p = Solution().deleterDuplicates2(head);
    while(p!=NULL) {
        printf("%d  ", p->val);
        p = p->next;
    }
    printf("\n");
    return 0;
}
