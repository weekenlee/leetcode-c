#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using std::vector;
using std::string;
using std::unordered_map;


class Solution {
    public:
        vector<int> findSubstring(string s, vector<string>& words) {
            vector<int> result;
            const int m = s.length();
            const int n = words.size();
            const int k = words.front().length();

            if(m < n * k) {
                return result;
            }

            unordered_map<string, int> lookup;
            for(const auto& word : words) {
                ++lookup[word];
            }

            for(int i = 0; i < k; ++i) {
                int left = i, count = 0;
                unordered_map<string, int> tmp;
                for(int j = i; j <= m - k; j += k) {
                    const auto& str = s.substr(j, k);
                    if(lookup.count(str)) {
                        ++tmp[str];
                        if(tmp[str] <= lookup[str]) {
                            ++count;
                        }else {
                            while (tmp[str] > lookup[str]) {
                                const auto& str1 = s.substr(left, k);
                                --tmp[str1];
                                if(tmp[str1] < lookup[str1]) {
                                    --count;
                                }
                                left += k;
                            }
                        }

                        if(count == n) {
                            result.emplace_back(left);
                            --tmp[s.substr(left, k)];
                            --count;
                            left += k;
                        }
                    }else {
                        tmp.clear();
                        count = 0;
                        left = j + k;
                    }
                }
            }
            return result;

        }
};

int main(void) 
{
    vector<string> vs = {
        "foo","bar"
    };

    Solution s;
    vector<int> result = s.findSubstring("barfoothefoobarman", vs);
    for (auto i : result) {
        std::cout<< i << " ";
    }
    std::cout<<std::endl;
}
