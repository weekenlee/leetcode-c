#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public:
        int removeElement(vector<int>&nums, int val) {
            int left = 0, right = nums.size();
            while(left < right) {
                if(nums[left] != val) {
                    ++left;
                }else {
                    swap(nums[left], nums[--right]);
                }
            }
            return right;
        }
};

int main(void)
{
    vector<int> v = {1,2,3,4,5};
    Solution().removeElement(v, 3);
    for(auto i : v) {
        cout << i;
    }
    cout <<endl;
}
