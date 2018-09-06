#include<iostream>

class Solution {
    public:
        bool isPalindrome(int x) {
            if(x < 0) {
                return false;
            }

            int temp = x;
            int reversed = 0;
            while(temp != 0) {
                reversed = reversed * 10 + temp % 10;
                temp = temp /10;
            }
            return reversed == x;
        }
};

int main(void) {
    Solution s;
    std::cout << s.isPalindrome(123321)<<std::endl;
    std::cout << s.isPalindrome(123320)<<std::endl;
    return 0;
}
