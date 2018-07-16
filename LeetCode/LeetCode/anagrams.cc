#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>

using std::string;
using std::vector;
using std::unordered_map;

class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            unordered_map<string, vector<string>> groups;
            for(const auto& str: strs) {
                std::cout<<"get "<<str<<std::endl;
                string tmp{str};
                sort(tmp.begin(), tmp.end());
                std::cout<<"sorted "<<tmp<<std::endl;
                groups[tmp].emplace_back(str);
            }

            vector<vector<string>> anagrams;
            for(const auto&kvp : groups) {
                vector<string> group;
                for(const auto&str :kvp.second) {
                    group.emplace_back(str);
                }

                //sort(group.begin(), group.end());
                anagrams.emplace_back(move(group));
            }

            return anagrams;
        }
};

int main(void)
{
    vector<string> src = {"eat", "tea","tan","ate","nat","bat"};
    Solution s;
    vector<vector<string>> result = s.groupAnagrams(src);
    for(const auto vs: result) {
        for(const auto s :vs) {
            std::cout<<s<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}
