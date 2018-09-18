#include<iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(NULL) {}
};

class Solution{
    public:
        ListNode *reverseBetween(ListNode *head, int m, int n) {
            ListNode dummy{0};
            dummy.next = head;

            auto *prev = &dummy;

            for(int i = 0; i < m - 1; ++i) {
                prev = prev -> next;
            }

            auto *head2 = prev;
            prev = prev -> next;
            auto *cur = prev->next;

            for(int i = m; i < n; ++i) {
                prev->next = cur->next;
            }

            for(int i = m; i < n; ++i) {
                prev->next = cur->next;
                cur->next = head2->next;
                head2->next = cur;
                cur = prev->next;
            }

            return dummy.next;
        }
};

int main(int argc, char ** argv)
{
    int i, count = argc - 3;

    ListNode dummy(-1);
    ListNode *prev = & dummy;
    ListNode *p;

    for (i = 0; i < count; ++i) {
        p = new ListNode(atoi(argv[i+3]));
        prev->next = p;
        prev = p;
    }

    int m = atoi(argv[1]);
    int n = atoi(argv[2]);
    struct ListNode *head = Solution().reverseBetween(dummy.next, m, n);
    for(p = head; p!=NULL; p = p->next)
    {
        printf("%d", p->val);
    }
    printf("\n");
    return 0;
};
