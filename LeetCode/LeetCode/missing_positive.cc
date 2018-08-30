#include<iostream>
#include<vector>
#include<algorithm>

using std::vector;
using std::swap;

class Solution {
    public:
        int firstMissingPositive(vector<int> &nums) {
            int i = 0;
            bucketSort(&nums);
            for(;i < nums.size() && nums[i] == i + 1; ++i);
            return i+1;
        }

    private:
        void bucketSort(vector<int> *nums) {
            int i = 0;
            while(i < nums->size()) {
                if((*nums)[i] > 0 && (*nums)[i] <= nums->size() && 
                        (*nums)[i] != (*nums)[(*nums)[i] - 1]) {
                    swap((*nums)[i], (*nums)[(*nums)[i] - 1]);
                }else {
                    ++i;
                }
            }
        }
};

int main()
{
    Solution s;
    vector<int> vc = {1,2,3,4,5,7};
    std::cout<<s.firstMissingPositive(vc)<<std::endl;
    return 0;
}
