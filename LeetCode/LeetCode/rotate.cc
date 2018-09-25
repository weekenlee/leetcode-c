#include<iostream>
#include<vector>

using namespace std;

class Solution{
    public:
        void rotate(vector<vector<int>> &matrix) {
            const int n = matrix.size();
            for(int i = i; i < n / 2; i++) {
                for(int j = i; j < n -1 -i; ++j) {
                    const auto tmp = matrix[i][j];
                    matrix[i][j] = matrix[n-1-j][i];
                    matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                    matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                    matrix[j][n-1-i] = tmp;
                }
            }
        }
};
