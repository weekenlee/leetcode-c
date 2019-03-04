#include<limits>
#include<vector>
using namespace std;
class Solution {
    public:
        struct Bucket {
            int max = numeric_limits<int>::max();
            int min = numeric_limits<int>::min();
        };

        int maximumGap(vector<int> &nums) {
            if(nums.size() < 2) {
                return 0;
            }

            int max_val = *max_element(nums.cbegin(), nums.cend());
            int min_val = *min_element(nums.cbegin(), nums.cend());

            int gap = max(1, static_cast<int>((max_val - min_val)
                        /(nums.size() - 1)));

            vector<Bucket> buckets((max_val - min_val)/ gap + 1);

            for(const auto &n : nums) {
                if ( n == max_val || n == min_val ) {
                    continue;
                }

                int i = (n - min_val) / gap;

                buckets[i].min = min(buckets[i].min, n);
                buckets[i].max = max(buckets[i].max, n);
            }

            int max_gap = 0, pre_bucket_max = min_val;
            for(const auto& bucket : buckets) {
                if(bucket.min != numeric_limits<int>::max()) {
                    max_gap = max(max_gap, bucket.min - pre_bucket_max);
                    pre_bucket_max = bucket.max;
                }
            }

            max_gap = max(max_gap, max_val - pre_bucket_max);

            return max_gap;
        }
};
