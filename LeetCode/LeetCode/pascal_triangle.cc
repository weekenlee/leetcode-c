#include<vector>
#include<iostream>
using std::vector;
class Solution {
    public:
        vector<vector<int>> generate(int numRows) {
            vector<vector<int>> vec;
            for(int i=0; i<numRows; ++i) {
                vector<int> row;
                if(!vec.empty()) {
                    row.assign(vec.at(i-1).begin(), vec.at(i-1).end());
                }
                for(auto o : row) {
                    std::cout << o << " ";
                }
                std::cout << std::endl;
                row.push_back(1);
                for(int j=i-1; j >0; --j) {
                    row[j] += row[j-1];
                }
                for(auto o : row) {
                    std::cout << o << " ";
                }
                std::cout << std::endl;
                std::cout << std::endl;
                vec.push_back(row);
            }
            return vec;
        }
};

int main() 
{
    Solution s;
    std::cout << std::endl;
    for(auto vec: s.generate(8)) {
        for(auto i : vec) {
            std::cout<<i<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}
