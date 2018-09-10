#include<iostream>
#include<vector>
#include<ostream>
#include<iterator>

using namespace std;

class Solution {
    public:
        vector<int> plusOne(vector<int> &digits) {
            for(int i = digits.size() -1; i >= 0; --i) {
                if (digits[i] == 9) {
                    digits[i]= 0;
                }else {
                    ++digits[i];
                    return digits;
                }
            }
            digits[0] = 1;
            digits.emplace_back(0);
            return digits;
        }
};


int main(void) {
    Solution s;
    vector<int> digits{2,2,3};
    auto r = s.plusOne(digits) ;
    for(auto i = r.begin(); i != r.end(); i++) {
       cout << *i <<endl; 
    }
}
