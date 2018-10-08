#include<iostream>

class Solution {
    public:
        int mySqrt(int x) {
            if (x < 2) {
                return x;
            }

            int left = 1, right = x/2;
            while(left <= right) {
                const auto mid = left +(right - left) / 2;
                if(mid > x/mid) {
                    right = mid - 1;
                }else {
                    left = mid + 1;
                }
            }

            return left - 1;
        }
};

int main(void)
{
    int result = Solution().mySqrt(10);
    std::cout << result << std::endl;
}
