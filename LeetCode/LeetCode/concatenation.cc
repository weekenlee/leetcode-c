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
                std::cout<<word<<" : "<<lookup[word]<<std::endl;
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


class Solution2 {
    public:
        vector<int> findSubstring(string s, vector<string>& words) {
            const auto word_length = words.front().length();
            const auto cat_length = word_length* words.size();
            vector<int> result;

            if(s.length() < cat_length) {
                return result;
            }

            unordered_map<string, int> wordCount;
            for(const auto &word : words) {
                ++wordCount[word];
            }

            for(auto it = s.begin(); it != prev(s.end(), cat_length-1); ++it) {
                unordered_map<string, int> unused(wordCount);
                for(auto jt = it; jt != next(it, cat_length); jt += word_length) {
                    auto pos = unused.find(string(jt, next(jt, word_length)));
                    if(pos == unused.end()) {
                        break;
                    }
                    if(--pos->second == 0) {
                        unused.erase(pos);
                    }
                }

                if(unused.empty()) {
                    result.emplace_back(distance(s.begin(), it));
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
    Solution2 s2;
    vector<int> result = s.findSubstring("barfoothefoobarman", vs);
    vector<int> result2 = s2.findSubstring("barfoothefoobarman", vs);
    for (auto i : result) {
        std::cout<< i << " ";
    }
    std::cout<<std::endl;
     for (auto i : result2) {
        std::cout<< i << " ";
    }
    std::cout<<std::endl;
}
