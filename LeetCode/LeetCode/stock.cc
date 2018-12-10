#include<vector>
#include<iostream>
#include<algorithm>
using std::vector;
using std::max;
using std::min;

class Solution {
    public:
        int maxProfit(vector<int> &prices) {
            if(prices.empty()) return 0;
            int ret{0},low{prices[0]};
            for(auto price : prices) {
                low = min(low, price);
                ret = max(ret, price - low);
            }
            return ret;
        }
};

int main()
{
    Solution s;
    std::vector<int> vec{2,4,3,7,9,2,5,6,10,1};
    std::cout << s.maxProfit(vec) << std::endl;
    return 0;
}
