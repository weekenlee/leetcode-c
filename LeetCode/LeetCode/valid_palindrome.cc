#include <string>
using std::string;
#include <cctype>

class Solution {
    public:
        bool isPalindrome(string s) {
            for(auto b = s.cbegin(), e = std::prev(s.cend()); b < e; ++b, --e) {
                while(!isalnum(*b)) ++b;
                while(!isalnum(*e)) --e;
                if( b < e &&tolower(*b) != tolower(*e)) {
                    return false;
                }
            }

            return true;
        }
};


#include <iostream>

int main() 
{
    std::cout << Solution().isPalindrome("race a car") << std::endl;
    std::cout << Solution().isPalindrome("A man, a plan, a canal: Panama") << std::endl;
}
