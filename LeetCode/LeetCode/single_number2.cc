
class Solution {
    public:
        int singleNumber(int A[], int n) {
            int low = 0;
            for( int i = 0, high = 0; i != n; ++i) {
                low ^= A[i] & ~high;
                high ^= A[i] & ~low;
            }
            return low;
        }
};

#include<iostream>

int main() {
    int A[13] = {8,9,13,44,13,9,44,9,44,13,8,5,8};
    std::cout << Solution().singleNumber(A,13) <<std::endl;
}
