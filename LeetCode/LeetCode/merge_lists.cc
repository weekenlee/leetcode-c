#include<iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
            ListNode dummy{0};
            auto curr = &dummy;

            while(l1 && l2) {
                if(l1->val <= l2->val) {
                    curr->next = l1;
                    l1 = l1->next;
                } else {
                    curr->next = l2;
                    l2 = l2->next;
                }
                curr = curr->next;
            }

            curr->next = l1 ? l2: l2;
            return dummy.next;
        }
};

int main(void)  
{
    Solution s;
    ListNode l1(1);
    ListNode l2(2);
    l1.next = &l2;
    ListNode l3(3);
    ListNode l4(4);
    l3.next = &l4;
    ListNode *result = s.mergeTwoLists(&l1, &l3);
    
    while(result != NULL) {
        std::cout<<result->val<<std::endl;
        result = result->next;
    }
}
