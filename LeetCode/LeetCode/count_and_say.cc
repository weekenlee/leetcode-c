#include<iostream>
#include<string>
#include<algorithm>
#include<functional>

using std::string;
using std::to_string;
using std::not_equal_to;

class Solution {
    public:
        string countAndSay(int n) {
            string seq{"1"};
            for(int i = 0; i < n - 1; ++i) {
                seq = getNext(seq);
            }
            return seq;
        }

    private:
        string getNext(const string &seq) {
            string next_seq;
            for(auto i = seq.cbegin(); i != seq.cend();) {
                auto j = find_if(i, seq.cend(), bind1st(not_equal_to<char>(), *i));
                next_seq.append(to_string(distance(i, j)));
                next_seq.push_back(*i);
                i = j;
            }
            return next_seq;
        }
};

int main(void)
{
    Solution s;
    std::cout<<s.countAndSay(5)<<std::endl;
    return 0;
}