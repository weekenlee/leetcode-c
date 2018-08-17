#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using std::vector;
using std::stack;
using std::max;
using std::min;


class Solution {
    public:
        int maximalRectangle(vector<vector<char>> &matrix) {
            if (matrix.empty() || matrix[0].empty()) {
                return 0;
            }

            int res = 0;
            vector<int> height(matrix[0].size(), 0);
            for(int i = 0; i < matrix.size(); i++) {
                for (int j = 0; j < matrix[0].size(); j++) {
                    height[j] = matrix[i][j] == '1' ? height[j] + 1 : 0 ;
                }
                res = max(res, largestRectangleArea(height));
            }
            return res;
        }


    private:
        int largestRectangleArea(const vector<int> &height) {
            stack<int> increasing_height;
            int max_area = 0;

            for (int i = 0; i <= height.size();) {
                if(increasing_height.empty() ||
                        (i < height.size() && height[i] > height[increasing_height.top()])) {
                    increasing_height.emplace(i);
                    ++i;
                } else {
                    auto h = height[increasing_height.top()];
                    increasing_height.pop();
                    auto left = increasing_height.empty() ? -1 : increasing_height.top();
                    max_area = max(max_area, h * (i - left - 1));
                }
            }
            return max_area;
        }
};

class Solution2 {
    public:
        int maximalRectangle(vector<vector<char>> &matrix) {
            if (matrix.empty()) {
                return 0;
            }

            const int m = matrix.size();
            const int n = matrix.front().size();
            int res = 0;
            vector<int> H(n, 0);
            vector<int> L(n, 0);
            vector<int> R(n, 0);

            for (int i = 0; i < m; ++ i) {
                int left = 0, right = n;
                for( int j = 0; j < n; j++ ) {
                    if (matrix[i][j] == '1') {
                        ++H[j];
                        L[j] = max(L[j], left);
                    } else {
                        left = j + 1;
                        H[j] = L[j] = 0;
                        R[j] = n;
                    }
                }

                for (int j = n - 1; j >= 0; --j) {
                    if (matrix[i][j] == '1') {
                        R[j] = min(R[j], right);
                        res = max(res,H[j] * (R[j] - L[j]));
                    }else {
                        right = j;
                    }
                }
            }
            return res;
        }
};

int main(void) {
    Solution s;
    Solution2 s2;
    vector<vector<char>> m = {
        {
            '1','0','1','0','0'
        },
        {
            '1','0','1','1','1'
        },
        {
            '1','1','1','1','1'
        },
        {
            '1','0','0','1','0'
        },
    };
    std::cout<<s.maximalRectangle(m)<<std::endl;
    std::cout<<s2.maximalRectangle(m)<<std::endl;
    return 0;
}
