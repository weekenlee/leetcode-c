#include<iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(NULL) {}
};

class Solution {
    public:
        ListNode *removeNthFromEnd(ListNode *head, int n) {
            ListNode dummy{0};
            dummy.next = head;
            auto slow = &dummy;
            auto fast = &dummy;

            while( n > 0) {
                fast = fast ->next;
                --n;
            }

            while(fast->next != nullptr) {
                slow = slow->next;
                fast = fast->next;
            }

            auto node_to_delete = slow->next;
            slow->next = slow->next->next;
            delete node_to_delete;

            return dummy.next;
        }
};

int main(int argc, char **argv)
{
	int i;
	struct ListNode *list, *p, *prev = NULL;
	for (i = 1; i < 5; i++) {
		p = new ListNode(i); 
		if (i == 1) {
			list = p;
		}
		if (prev != NULL) {
			prev->next = p;
		}
		prev = p;
	}
	
    Solution s;
	list = s.removeNthFromEnd(list,2);
	if (list != NULL) {
		for (p = list; p != NULL; p = p->next) {
			printf("%d\n", p->val);
		}
	}
	return 0;
}
