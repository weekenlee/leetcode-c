#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            const auto start = lower_bound(nums.cbegin(), nums.cend(), target);
            const auto end = upper_bound(nums.cbegin(), nums.cend(), target);
            if(start != nums.cend() && *start == target) {
                return {start-nums.cbegin(), end-nums.cbegin()-1}; 
            }

        }
};

int main(void)
{
    Solution s;
    vector<int> nums = {2,4,4,4,6,8,10 };
    auto result = s.searchRange(nums, 4);
    for (auto i : result) {
        cout << i; 
    }
    cout<<endl;
    return 0;
}

