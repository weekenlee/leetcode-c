#include<iostream>

using namespace std;

class Solution {
    public:
        double myPow(double x, int n) {
            double result = 1;
            long long abs_n = abs(static_cast<long long>(n));
            while(abs_n > 0) {
                if (abs_n & 1) {
                    result *= x;
                }
                abs_n >>= 1;
                x *= x;
            }
            return n < 0 ? 1/result : result;
        }
};

class Solution2 {
    public:
        double myPow(double x,int n) {
            if (n < 0 && n != -n) {
                return 1.0/myPow(x, -n);
            } 

            if (n == 0) {
                return 1;
            }

            double v = myPow(x, n/2);
            if (n % 2 == 0) {
                return v*v;
            }else {
                return v * v * x;
            }
        }
};

int main(int argc, char* argv[]) 
{
    Solution s;
    cout << s.myPow(2.0, 2) << endl;
    Solution2  s2;
    cout << s2.myPow(2.0, 2) << endl;
    return 0;
}
