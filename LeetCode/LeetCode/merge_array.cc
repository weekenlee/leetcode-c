#include<iostream>
#include<vector>

using std::vector;

class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            int i = m + n;
            while (m > 0 && n > 0) {
                if (nums1[m - 1] > nums2[n - 1]) {
                    nums1[i - 1] = nums1[m - 1];
                    --m;
                } else {
                    nums1[i - 1] = nums2[n - 1];
                    --n;
                }
                --i;
            }

            while(n > 0) {
                nums1[i - 1] = nums2[n - 1];
                --n;
                --i;
            }
        }
};

int main(void) 
{
    Solution s;
    vector<int> v1 = {1, 2,4,6, 0, 0, 0,0};
    vector<int> v2 = {3, 5,7,8};
    
    s.merge(v1, 4, v2, 4);
    for(auto i = v1.begin(); i != v1.end(); i++) {
        std::cout<<*i<<" ";
    }
    std::cout<<std::endl;

}
