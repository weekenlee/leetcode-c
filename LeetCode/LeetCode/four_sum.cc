
class Solution {
    public:
        vector<vector<int>> fourSum(vector<int> &num, int target) {
            int len = num.size();
            int left, right, sum;
            sort(num.begin(), num.end());
            vector<vector<int>> res;

            for(int i = 0; i < len - 3; ++i) {
                if( i && num[i] == num[i-1]) {
                    continue
                }

                for(int j = i + 1; j < len - 2; ++j) {
                    if(j != i + 1 && num[j] == num[j - i]) {
                        continue;
                    }

                    sum = target - num[i] - num[j];
                    left = j + 1, right = len - 1;
                    while(left < right) {
                
                    }
                }
            }
        }
};
