#include<iostream>
#include<string>
#include<vector>
#include<iterator>
#include<algorithm>

using std::string;
using std::vector;
using std::transform;
using std::back_inserter;
using std::cout;
using std::endl;

class Solution {
    public:
        string multiply(string num1, string num2) {
            const auto char_2_int = [](const char c) { return c - '0';};
            const auto int_2_char = [](const int i) { return i + '0';};

            vector<int> n1;
            transform(num1.rbegin(), num1.rend(), back_inserter(n1), char_2_int);
            vector<int> n2;
            transform(num2.rbegin(), num2.rend(), back_inserter(n2), char_2_int);

            vector<int> tmp(n1.size() + n2.size());
            for(int i = 0; i < n1.size(); ++i) {
               for(int j = 0; j < n2.size(); ++j) {
                    tmp[i + j] += n1[i] * n2[j];
                    tmp[i +j + 1] += tmp[i + j]/10;
                    tmp[i+j] %= 10;
                }
            }

            string res;
            transform(find_if(tmp.rbegin(), prev(tmp.rend()), 
                        [](const int i) { return i != 0;}),
                    tmp.rend(), back_inserter(res), int_2_char);
            return res;
        }
};

int main(void) 
{
    Solution s;
    cout << s.multiply("123", "12")<<endl;
    return 0;
}
