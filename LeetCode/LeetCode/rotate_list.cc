#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(NULL) {}
};

class Solution{
    public:
        ListNode *rotateRight(ListNode *head, int k) {
            if (head == nullptr || head->next == nullptr) {
                return head;
            }

            int n = 1;
            auto curr = head;

            for(;curr->next; curr = curr->next) {
                ++n;
            }
            curr->next = head;

            auto tail = curr;
            k = n - k % n;
            curr = head;
            for(int i = 0; i < k; curr = curr->next, ++i) {
                tail = curr;
            }

            tail->next = nullptr;
            return curr;
        }
};

int main(int argc, char **argv){
    int i;
    ListNode *p, *prev, *dummy, *list;
    dummy = new ListNode(-1);
    prev = dummy;
    for (i = 2; i < argc; i++) {
        int n = atoi(argv[i]);
        p = new ListNode(n);
        prev->next = p;
        prev = p;
    }
    for (p = dummy->next; p != NULL; p = p->next) {
        printf("%d ", p->val);
    }
    putchar('\n');

    list = Solution().rotateRight(dummy->next, atoi(argv[1]));

    for (p = list; p != NULL; p = p->next) {
        printf("%d ", p->val);
    }
    putchar('\n');

    return 0;
}
