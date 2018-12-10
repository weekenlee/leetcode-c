#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

class Solution {
    public:
        int minimumTotal(vector<vector<int>> &triangle) {
            vector<int> steps;
            for(auto &v : triangle) {
                if(!steps.empty()) {
                    v.front() += steps.front();
                    v.back() += steps.back();
                }

                for(size_t i = 1; i < steps.size();  ++i) {
                    v[i] += min(steps.at(i - 1), steps.at(i));
                }

                steps = v;
            }
            return *min_element(steps.cbegin(), steps.cend());
        }
};

int main() 
{
    Solution s;
    vector<vector<int>> vec{{-7},{-2,1},{-5,-5,9},{-4,-5,4,4},{-6,-6,2,-1,-5},{3,7,8,-3,7,-9},{-9,-1,-9,6,9,0,7},{-7,0,-6,-8,7,1,-4,9},{-3,2,-6,-9,-7,-6,-9,4,0},{-8,-6,-3,-9,-2,-6,7,-5,0,7},{-9,-1,-2,4,-2,4,4,-1,2,-5,5},{1,1,-6,1,-2,-4,4,-2,6,-6,0,6},{-3,-3,-6,-2,-6,-2,7,-9,-5,-7,-5,5,1}};
    std::cout << s.minimumTotal(vec);
}
