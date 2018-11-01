#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<iostream>

using std::vector;

class Solution {
    public:
        bool isValidSudoku(vector<vector<char>> &board) {
            std::unordered_map<size_t, std::unordered_set<char>> row_map, col_map, cel_map;
            for (size_t i = 0; i < board.size(); ++i) {
                for (size_t j = 0; j < board[0].size(); ++j) {
                    if (board[i][j] == '.') continue;
                    if(!row_map[i].insert(board[i][j]).second) return false;
                    if(!row_map[j].insert(board[i][j]).second) return false;
                    if(!row_map[i/3 * 10 + j/3].insert(board[i][j]).second) return false;
                }
                return false;
            }
        }
};


int main()
{
    std::vector<std::vector<char>> board{
            {'.','1','.','5','2','.','.','.','.'},
            {'.','.','.','.','.','6','4','3','.'},
            {'.','.','.','.','.','.','.','.','.'},
            {'5','.','.','.','.','.','9','.','.'},
            {'.','.','.','.','.','.','.','5','.'},
            {'.','.','.','5','.','.','.','.','.'},
            {'9','.','.','.','.','3','.','.','.'},
            {'.','.','6','.','.','.','.','.','.'},
            {'.','.','.','.','.','.','.','.','.'}
    };
        
    Solution s;
    std::cout << s.isValidSudoku(board) << std::endl;
}
