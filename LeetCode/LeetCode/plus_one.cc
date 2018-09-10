#include<iostream>
#include<vector>
#include<ostream>
#include<iterator>
#include<algorithm>

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

class Solution2 {
    public:
        vector<int> plusOne(vector<int>& digits) {
            vector<int> result(digits.rbegin(), digits.rend());
            int carry = 1;
            for(auto &num : result) {
                num += carry;
                carry = num / 10;
                num %= 10;
            }
            if (carry == 1) {
                result.emplace_back(carry);
            }
            reverse(result.begin(), result.end());
            return result;
        }
};

int main(void) {
    Solution s;
    vector<int> digits{2,2,3};
    auto r = s.plusOne(digits) ;
    for(auto i = r.begin(); i != r.end(); i++) {
       cout << *i <<endl; 
    }
    vector<int> digits2{2,2,3};
    Solution2 s2;
    r = s2.plusOne(digits2) ;
    for (auto &i : r) {
        cout << i <<endl;
    }
}
