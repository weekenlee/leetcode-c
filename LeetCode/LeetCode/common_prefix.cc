#include<iostream>
#include<string>
#include<vector>

using std::vector;
using std::string;
using std::cout;
using std::endl;

class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {

            if(strs.empty()) {
                return "";
            }

            for(int i = 0; i < strs[0].length();++i) {
                for (const auto& str : strs) {
                    if(i >= str.length() || str[i] != strs[0][i]) {
                        return strs[0].substr(0, i);
                    }
                }
            }
            return strs[0];
        }

};


int main(void)
{
    Solution s;
    vector<string> input{"abdc", "abde", "abd"};
    std::cout<< s.longestCommonPrefix(input)<<std::endl;
    return 0;
}
