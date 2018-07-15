#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
    public:
       ListNode* addTwoNumbers(ListNode *l1, ListNode *l2) {
           ListNode dummy{0};
           auto curr = &dummy;
           auto carry = 0;
           while (l1 || l2 || carry) {
               auto a = l1 ? l1->val:0;
               auto b = l2 ? l2->val:0;
               auto val = carry + a + b;
               std::cout<<a<<b<<carry<<val<<std::endl;
               curr->next = new ListNode(val % 10);
               carry = val / 10;
               l1 = l1 ? l1->next :nullptr;
               l2 = l2 ? l2->next :nullptr;
               curr = curr->next;
           }
           return dummy.next;
       }
};

int main()
{
    ListNode root = ListNode(1);
    ListNode *prev = &root;
    for (int i = 0; i < 2; ++i) {
        ListNode *node = new ListNode(i);
        prev->next = node;
        prev = prev->next;
    }
    prev->next=nullptr;
    ListNode *l1 = &root;
    ListNode *pl1 = l1;
    while(pl1!= nullptr) {
        std::cout<<pl1->val<<" ";
        pl1=pl1->next;
    }
    std::cout<<std::endl;


    ListNode root2 = ListNode(2);
    prev = &root2;
    for (int i = 0; i < 2; ++i) {
        ListNode *node = new ListNode(i+3);
        prev->next = node;
        prev = prev->next;
    }
    prev->next = nullptr;
    ListNode *l2 = &root2;
    ListNode *pl2 = l2;
    while(pl2!= NULL) {
        std::cout<<pl2->val<<" ";
        pl2=pl2->next;
    }
    std::cout<<std::endl;

    Solution s;
    ListNode *result = s.addTwoNumbers(l1, l2);
    while(result != NULL) {
        std::cout<<result->val<<" ";
        result=result->next;
    }
    std::cout<<std::endl;
    return 0;
}
