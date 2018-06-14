#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

static bool
dfs(char **word, char **board,  bool *used
        int row, int col, int row_size, int col_size)
{
    if(board[row][col] != *word){
        return false;
    }

    used[row * col_size + col] = true;

    if(*(word+1) == '\0') {
        return true;
    }

    bool result = false;

    if(row > 0&& ！used[(row - 1)*col_size + col]) {
        result = dfs(word+1, board, used, row - 1, col, row_size, col_size);
    }
}
