#include<iostream>
#include<vector>

using namespace std;

class Solution {
    public:
        vector<vector<int>> subsets(vector<int> &nums) {
            vector<vector<int>> result(1);
            sort(nums.begin(), nums.end());
            for( size_t i = 0; i < nums.size(); ++i) {
                const size_t size = result.size();
                for (size_t j = 0 ; j < size; ++j) {
                    result.emplace_back(result[j]);
                    result.back().emplace_back(nums[i]);
                }
            }
            return result;
        }
};

int main(void) {
    vector<int> v={1,2,3,4};
    auto result = Solution().subsets(v);
    for(auto i : result) {
        for( auto j : i ) {
            cout << j << " ";
        }
        cout << endl;
    }
}
