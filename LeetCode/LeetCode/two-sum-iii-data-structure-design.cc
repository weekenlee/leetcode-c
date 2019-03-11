#include<unordered_map>
using namespace std;
class TwoSum {
    public:
        void add(int number) {
            ++lookup_[number];
        }

        bool find(int value) {
            for(const auto& kvp : lookup_) {
                const auto num = value - kvp.first;
                if(lookup_.count(num) && (num != kvp.first || kvp.second > 1)) {
                    return true;
                }
            }
            return false;
        }

    private:
        unordered_map<int, int> lookup_;
};
