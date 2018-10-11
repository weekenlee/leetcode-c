#include<iostream>
#include<vector>

using namespace std;

class Solution {
    public:
        vector<vector<int>> subsetWithDup(vector<int> &nums) {
            vector<vector<int>> result(1);
            sort(nums.begin(), nums.end());
            size_t previous_size = 0;
            for( size_t i = 0; i < nums.size(); ++i) {
                const size_t size = result.size();
                for( size_t j = 0; j < size; ++j  ) {
                    if(i == 0 || nums[i] != nums[i-1] || j >= previous_size) {
                        result.emplace_back(result[j]);
                        result.back().emplace_back(nums[i]);
                    }
                }
                previous_size=size;
            }
            return result;
        }
};

int main(void) {
    vector<int> v={1,2,3,4,4};
    auto result = Solution().subsetWithDup(v);
    for(auto i : result) {
        for( auto j : i ) {
            cout << j << " ";
        }
        cout << endl;
    }
}
