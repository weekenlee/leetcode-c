#include<vector>
#include<iostream>
using namespace std;

class Solution {
    public:
        int rob(vector<int> &nums) {
            int last = 0  , result = 0;
            for(const auto& i : nums) {
                auto tmp = result;
                result = max(last + i, result);
                last = tmp;
            }
            return result;
        }
};

int maitor() {
    vector<int> v{1,2,3,1};
    cout << Solution().rob(v) <<endl;
}
