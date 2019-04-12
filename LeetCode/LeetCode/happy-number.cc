#include<unordered_set>
#include<iostream>
#include<cmath>
using namespace std;

class Solution {
    public:
        bool isHappy(int n) {
            unordered_set<int> visited;
            while ( n != 1 && !visited.count(n)) {
                visited.emplace(n);
                n = nextNumber(n);
            }
            return n == 1;
        }

        int nextNumber(int n) {
            int sum = 0;
            while (n) {
                sum += pow(n % 10, 2);
                n /= 10;
            }
            return sum;
        }
};

int main() {
    cout << Solution().isHappy(10) <<endl;
}
