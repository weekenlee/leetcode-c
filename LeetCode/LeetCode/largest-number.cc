#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
    public:
        string largestNumber(vector<int>& nums) {
            sort(nums.begin(), nums.end(), [](const int &i, const int &j) {
                    return to_string(i) + to_string(j) > to_string(j) + to_string(i);
                    });
            
            string max_num;
            for(const auto& i : nums) {
                max_num.append(to_string(i));
            }

            if(!max_num.empty() && max_num[0] == '0') {
                return "0";
            }

            return max_num;
        }
};

int main() 
{
    vector<int> v{1,2,3,4,5,3};
    cout << Solution().largestNumber(v) <<endl;
}
