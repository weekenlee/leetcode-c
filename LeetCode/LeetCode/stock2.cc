#include<vector>
#include<iostream>
using std::vector;

class Solution {
    public:
    int maxProfit(vector<int> &prices) {
        int profit = 0;
        for ( auto i = prices.begin(); i != prices.end(); i++) {
            if(i + 1 != prices.end() && *(i + 1) > *i) {
                profit += *(i + 1) - *i;
            }
        }
        return profit;
    }
};

int main() 
{
    vector<int> prices = {4, 3, 4, 5, 7, 8, 9, 10, 4, 6, 3};
    Solution s;
    std::cout << s.maxProfit(prices) << std::endl;
}
