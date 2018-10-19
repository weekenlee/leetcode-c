#include <string>
#include <stack>
#include <iostream>

using std::string;
using std::stack;

class Solution {
    public:
        bool isValid(string s) {
            stack<char> stk;
            for (auto c : s) {
                if (!stk.empty() && 
                        ((c == ')' && stk.top()=='(') ||
                          (c == '}' && stk.top() == '{')||
                          (c == ']' && stk.top() == '['))) {
                    stk.pop();
                } else {
                    stk.push(c);
                }
            }

            return stk.empty();
        }
};

int main(void) {
    std::cout << Solution().isValid("()()")<<std::endl;
    std::cout << Solution().isValid("(()")<<std::endl;
    return 0;
}
