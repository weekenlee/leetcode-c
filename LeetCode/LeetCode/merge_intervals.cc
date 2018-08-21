#include<iostream>
#include<vector>
#include<algorithm>

using std::vector;
using std::max;

struct Interval {
    int start;
    int end;
    Interval(): start(0), end(0) {}
    Interval(int s, int e):start(s), end(e) {}
};

class Solution {
    public:
        vector<Interval> merge(vector<Interval> & intervals) {
            if (intervals.empty()) {
                return intervals;
            }

            sort(intervals.begin(), intervals.end(), 
                [] (const Interval &a, const Interval &b) {
                    return a.start < b.start;
                });

            vector<Interval> result{intervals[0]};

            for(int i = 1; i < intervals.size(); ++i) {
                if(intervals[i].start <= result.back().end) {
                    result.back().end = max(result.back().end, intervals[i].end);
                } else {
                    result.emplace_back(intervals[i]);
                }
            }
            return result;
        }
};

int main(void)
{
    Solution s;
    vector<Interval> v = {Interval(1,2), Interval(3,6), Interval(4,7)};
    auto result = s.merge(v);
    for(auto i = result.begin(); i < result.end(); i++) {
        std::cout<<(*i).start << " "<<(*i).end <<" , ";
    }
    std::cout<<std::endl;
}
