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

std::ostream& operator<<(std::ostream& o, std::vector<int> const& v) 
{
    for(auto i = v.begin(), end = v.end(); i != end; i++) {
        o << *i <<' ';
    }
}

int main(void) 
{
    Solution s;
    std::cout<<s.grayCode(5)<<std::endl;
}
