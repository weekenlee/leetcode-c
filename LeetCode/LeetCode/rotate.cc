#include<iostream>
#include<vector>

using namespace std;

class Solution{
    public:
        void rotate(vector<vector<int>> &matrix) {
            const int n = matrix.size();
            for(int i = 0; i < n / 2; i++) {
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

int main(int argc, char **argv)
{
    if (argc != 3) {
        fprintf(stderr, "Usage: ./test 3 3\n");
    }

    int i, j, count = 0;
    int row_size = atoi(argv[1]);
    int col_size = atoi(argv[2]);
    vector<vector<int>> v{};
    for (i = 0; i < row_size; i++) {
        vector<int> vv{};
        for (j = 0; j < col_size; j++) {
            vv.push_back(++count);
        }
        v.push_back(vv);
    }

    Solution().rotate(v);
    for (i = 0; i < col_size; i++) {
        for (j = 0; j < row_size; j++) {
            printf("%02d ",v[i][j]);
        }
        putchar('\n');
    }

    return 0;
}
