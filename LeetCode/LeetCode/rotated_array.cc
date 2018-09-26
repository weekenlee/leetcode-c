#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
        int search(vector<int> &nums, int target) {
            int left = 0, right = nums.size() - 1;

            while(left <= right) {
                int mid = left + (right - left) / 2;
                if(nums[mid] == target) {
                    return mid;
                }else if((nums[mid] >= nums[left] && nums[left] <= target && target <= nums[mid] ) || 
                        (nums[mid] < nums[left] && !(nums[mid] < target && target <= nums[right]))) {
                    right = mid - 1;
                }else {
                    left = mid + 1;
                }
            }
            return -1;
        }
};

int main()
{
	vector<int> nums{ 4,5,6,1,2,3 };
	printf("%d\n", Solution().search(nums, 3));
	return 0;
}
