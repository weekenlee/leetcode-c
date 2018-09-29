#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
        void setZeroes(vector<vector<int>>& matrix) {
            if (matrix.empty()) {
                return;
            }

            bool has_zero = false;
            int zero_i = -1,  zero_j = -1;

            for(int i = 0; i < matrix.size(); ++i) {
                for (int j = 0; j < matrix[0].size(); ++j) {
                    if(matrix[i][j] == 0) {
                        if(!has_zero) {
                            zero_i = i;
                            zero_j = j;
                            has_zero=true;
                        }

                        matrix[zero_i][j] = 0;
                        matrix[i][zero_j] = 0;
                    }
                }
            }

            if(has_zero){
                for(int i = 0; i < matrix.size(); ++i) {
                    if (i == zero_i) {
                        continue;
                    }

                    for(int j = 0; j < matrix[0].size(); ++j) {
                        if(j==zero_j) {
                            continue;
                        }
                        if(matrix[zero_i][j] == 0 || matrix[i][zero_j]==0 ) {
                            matrix[i][j] = 0;
                        }
                    }

                    for(int i = 0; i < matrix.size(); ++i) {
                        matrix[i][zero_j] = 0;
                    }
                    for(int j = 0; j < matrix.size(); ++j) {
                        matrix[zero_i][j] = 0;
                    }
                }
            }
        }
};

int main(int argc, char** argv)
{
    int rowsize = 2;
    int colsize = 2;
    vector<vector<int>> a;
    for(int i = 0; i < rowsize; i++) {
        vector<int> b;
        for(int j = 0; j < colsize; j++){
            b.push_back(i);
        }
        a.push_back(b);
    }
    for(int i = 0; i < rowsize; i++){
        for(int j = 0; j < colsize; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("setZero\n");
    Solution().setZeroes(a);
    for(int i = 0; i < rowsize; i++){
        for(int j = 0; j < colsize; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
