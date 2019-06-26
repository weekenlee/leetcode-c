#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        bool containsDuplicate(vector<int>& nums) {
            unordered_set<int> nums_set(nums.begin(), nums.end());
            return nums_set.size() != nums.size();
        }
};


class Solution2 {
    public:
        bool containsDuplicate(vector<int> &nums) {
            sort(nums.begin(), nums.end());
            return unique(nums.begin(), nums.end()) != nums.end();
        }
};

#include<iostream>

int main()
{
    Solution s;
    Solution2 s2;
    vector<int> v{1,2,3,1};
    cout << s.containsDuplicate(v) <<endl;
    cout << s2.containsDuplicate(v) <<endl;
}
