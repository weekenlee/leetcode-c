#include<iostream>
#include<string>

using std::string;

class Solution {
    public:
        int numDecoding(string s) {
            if(s.empty()) {
                return 0;
            }

            int prev = 0;
            int cur = 1;

            for(unsigned int i = 0; i < s.length(); ++i) {
                if (s[i] == '0') {
                    cur = 0;
                }

                if(i == 0 || !(s[i - 1] == '1' || (s[i-1] == '2' && s[i] <= '6'))) {
                    prev = 0;
                }

                int tmp = cur;
                cur += prev;
                prev = tmp;
            }
            return cur;
        }
};

int main(void)
{
    Solution s;
    std::cout<<s.numDecoding("12")<<std::endl;
    std::cout<<s.numDecoding("A")<<std::endl;
    std::cout<<s.numDecoding("AB")<<std::endl;
    return 0;
}
