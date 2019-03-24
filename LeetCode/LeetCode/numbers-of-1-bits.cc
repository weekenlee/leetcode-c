#include<cstdlib>

class Solution {
    public:
        int hammingweight(uint32_t n) {
            int count = 0;
            for(; n ; n &= n - 1) {
                ++count;
            }
            return count;
        }
};

#include<iostream>
using namespace std;
int main() {
    cout << Solution().hammingweight(18) <<endl;
}
