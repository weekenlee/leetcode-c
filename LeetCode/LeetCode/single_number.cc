class Solution {
    public :
        int singleNumber(int A[], int n) {
            int r{0};
            for (int i = 0; i != n; ++i) {
                r ^= A[i];
            }
            return r;
        }
};

#include<iostream>

int main() {
    Solution s;
    int A[7] = {1,2,3,5,2,1,3};
    std::cout << s.singleNumber(A, 7) << std::endl;
}
