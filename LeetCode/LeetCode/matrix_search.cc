#include<iostream>
#include<vector>

using std::vector;

class Solution {
    public:
        bool searchMatrix(vector<vector<int>> &matrix, int target) {
            if (matrix.empty()) {
                return false;
            }

            const int  m = matrix.size();
            const int n = matrix[0].size();
            int left = 0;
            int right = m * n - 1;

            while( left <= right) {
                int mid = left + (right - left)/2;
                if(matrix[mid /n][mid %n] >= target) {
                    right = mid - 1;
                }else {
                    left = mid + 1;
                }
            }

            if (left != m*n && matrix[left / n][left % n] == target) {
                return true;
            }

            return false;
        }
};

int main() {
    Solution s;
    vector<vector<int>> v = {
        {
            1,2,3,4,5
        },
        {
            6,7,8,9,10
        },
        {
            11,12,13,14,15
        }
    };

    std::cout<<s.searchMatrix(v, 99)<<std::endl;
    std::cout<<s.searchMatrix(v, 8)<<std::endl;
    return 0;
}
