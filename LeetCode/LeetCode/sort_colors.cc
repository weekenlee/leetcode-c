#include<iostream>
#include<vector>

using namespace std;

class Solution {
    public:
        void sortColors(vector<int> &nums) {
            const int target = 1;
            for(int i = 0, j = 0, n = nums.size()-1; j <=n;) {
                if (nums[j] < target) {
                    swap(nums[i++], nums[j++]);
                }else if(nums[j] > target) {
                    swap(nums[j], nums[n--]);
                }else {
                    ++j;
                }
            }
        }
};


int main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test colors\n");
        exit(-1);
    }
    int i, count = strlen(argv[1]);
    vector<int> nums;
    for (i = 0; i < count; i++) {
        nums.push_back(argv[1][i] - '0');
    }
    Solution().sortColors(nums);
    for (i = 0; i < count; i++) {
        printf("%d", nums[i]);
    }
    printf("\n");
    return 0;
}
