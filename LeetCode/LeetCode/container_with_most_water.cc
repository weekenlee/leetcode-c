#include<iostream>
#include<vector>
#include<algorithm>

using std::max;
using std::min;
using std::vector;

class Solution {
    public:
        int maxArea(vector<int>& height) {
            int i = 0, j = height.size() - 1, max_area = 0;
            while(i < j) {
                max_area = max(max_area, min(height[i], height[j]) * (j - i));
                if (height[i] > height[j]) {
                    --j;
                }else if(height[i] < height[j]) {
                    ++i;
                }else {
                    ++i, --j;
                }
            }
            return max_area;
        }
};

int main(void)
{
    vector<int> v{1,4,5,10};
    Solution s;
    std::cout<<s.maxArea(v)<<std::endl;
    return 0;
}

