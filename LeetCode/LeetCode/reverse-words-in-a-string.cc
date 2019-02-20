#include<iostream>
#include<string>

using namespace std;

class Solution {
    public:
        void reverseWords(string &s) {
            reverse(s.begin(), s.end());

            size_t begin = 0 , end = 0, len = 0;
            while((begin = s.find_first_not_of(" ", end)) != string::npos) {
                if((end = s.find(" ", begin)) == string::npos)  {
                    end = s.length();
                }

                reverse(s.begin() + begin, s.begin() + end);

                move(s.begin() + begin, s.begin() + end, s.begin() + len);
                len += end - begin;
                s[len++] = ' ';
            }
            s.resize(len ? len - 1 : 0);
        }
};

int main() 
{
    Solution s;
    string as = "hello world";
    s.reverseWords(as);
    cout << as << endl;
}
