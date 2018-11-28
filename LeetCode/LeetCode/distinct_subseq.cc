#include<string>
using std::string;
#include<vector>
using std::vector;
#include<iostream>

class Solution {
    public:
        int numDistinct(string s, string t) {
            int m = static_cast<int>(s.size());
            int n = static_cast<int>(t.size());

            if (m < n) return 0;

            vector<int> v(n+1, 0);
            v[0] = 1;
            for(int i = 1; i <= m; ++i) {
                for (int j = std::min(i, n) + 1; j > 0; --j) {
                    if(s[i - 1] == t[j - 1]) {
                        v[j] += v[j - 1];
                    }
                }
            }
            return v.back();
        }
};

int main(int argc, char **argv) 
{
    std::cout << Solution().numDistinct(argv[1], argv[2]) << std::endl;
    return 0;
}
