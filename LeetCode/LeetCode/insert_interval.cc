#include<iostream>
#include<vector>

using std::vector;
using std::max;
using std::min;
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e): start(s), end(e) {}
};

class Solution {
    public:
        vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
            size_t i = 0;
            vector<Interval> result;

            while(i < intervals.size() && newInterval.start > intervals[i].end) {
                result.emplace_back(intervals[i++]);
            }

            while(i < intervals.size() && newInterval.end >= intervals[i].start) {
                newInterval = {min(newInterval.start, intervals[i].start), max(newInterval.end, intervals[i].end)};
                ++i;
            }
            result.emplace_back(newInterval);

            result.insert(result.end(), intervals.cbegin() + i, intervals.cend());
            return result;
        }
};

std::ostream& operator<<(std::ostream& o, std::vector<Interval> const& v) 
{
    for(auto i = v.begin(), end = v.end(); i != end; ++i) {
        o << "{"<< i->start<<"-"<< i->end <<"} ";
    }
    return o;
}

int main()
{
    Solution s;
    Interval newin = {3, 6};
    vector<Interval> vs = {
        {1,2},
        {4,6},
        {7,9}
    };
    std::cout<<s.insert(vs, newin)<<std::endl;
}
