#include<iostream>
#include<vector>

using namespace std;

class Solution {
    public:
        int findMin(vector<int> &nums) {
            int left = 0, right = nums.size() - 1;

            while(left < right && nums[left] >= nums[right]) {
                int mid = left + (right - left)/2 ;
                if(nums[mid] < nums[left]) {
                    right = mid;
                }else {
                    left = mid + 1;
                }
            }
            return nums[left];
        }
};

int main() 
{
    Solution s;
    vector<int> v{4, 5, 6, 7, 8,  1, 2, 3};
    cout << s.findMin(v) << endl;
}
