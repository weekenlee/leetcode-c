#include <vector>
#include <algorithm>

using namespace std;

class Solution2 {
    public:
        int findKthLargest(vector<int>& nums, int k) {
            nth_element(nums.begin(), next(nums.begin(), k - 1), nums.end(), greater<int>());
            return *next(nums.begin(), k - 1);
        }
};


#include<iostream>
int main()
{
    vector<int> v{4,5,6,2,1,9};
    cout << Solution2().findKthLargest(v, 1) <<endl;
    cout << Solution2().findKthLargest(v, 2) <<endl;
}
