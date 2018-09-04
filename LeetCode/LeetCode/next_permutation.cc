#include<iostream>
#include<vector>
#include<iterator>
#include<functional>
#include<algorithm>

using std::vector;
using std::reverse_iterator;
using std::bind1st;
using std::less;
using std::find_if;
using std::reverse;
using std::swap;

class Solution {
    public:
        void nextPermutation(vector<int> &num) {
            nextPermutation(num.begin(), num.end());
        }

    private:
        template<typename BidiIt>
        bool nextPermutation(BidiIt begin, BidiIt end) {
           const auto rbegin = reverse_iterator<BidiIt>(end); 
           const auto rend= reverse_iterator<BidiIt>(begin); 

           auto pivot = next(rbegin);
           while ( pivot != rend && *pivot >= *prev(pivot)) {
                ++pivot;
           }

           bool is_greater = true;
           if(pivot != rend) {
                auto change = find_if(rbegin, pivot, bind1st(less<int>(), *pivot));
                swap(*change, *pivot);
           } else {
                is_greater = false;
           }

           reverse(rbegin, pivot);
           return is_greater;
        }
};

int main(void) 
{
    vector<int> nums{1,2,3,5,4};
    Solution s;
    s.nextPermutation(nums);
    for(auto x : nums) {
        std::cout << x <<" ";
    }
    std::cout<<std::endl;
    return 0; 
}
