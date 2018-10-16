#include<vector>
#include<algorithm>
#include<iostream>

using std::vector;

class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        std::sort(nums.begin(), nums.end());
        int min{INT_MAX}, sum{0}, tmpsum{0};
        for( auto it = nums.cbegin(); it!=nums.cend(); ++it ) {
            for(auto b = std::next(it), e = std::prev(nums.cend()); b<e; tmpsum < target?--e:++b) {
                if((tmpsum = *it + *b + *e) == target) return target;
                else if(std::abs(tmpsum-target < min)) {
                    sum = tmpsum;
                    min = std::abs(tmpsum - target);
                }
            }
        }
        return sum;
    }
};

