#include<iostream>
#include<vector>

using std::vector;
class Solution {
    public:
        vector<int> grayCode(int n) {
            vector<int> result = {0};
            for(int i = 0; i < n ; i++) {
                for(int j = result.size() - 1; j >= 0; --j) {
                    result.emplace_back(1 << i | result[j]);
                }
            }
            return result;
        }
};

class Solution2 {
    public:
        vector<int> grayCode(int n) {
            vector<int> result;
            for(int i = 0; i < 1 << n; ++i) {
                result.emplace_back(i >> 1^i);
            }
            return result;
        }
};

std::ostream& operator<<(std::ostream& o, std::vector<int> const& v) 
{
    for(auto i = v.begin(), end = v.end(); i != end; ++i) {
        o << *i <<' ';
    }
    return o;
}

int main(void) 
{
    Solution s;
    Solution2 s2;
    auto v = s.grayCode(5);
    auto v2 = s2.grayCode(5);
    std::cout<<v<<std::endl;
    std::cout<<v2<<std::endl;
}
