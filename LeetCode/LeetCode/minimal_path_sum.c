#include<stdio.h>
#include<stdlib.h>
#include<string.h>

static inline int min(int a, int b)
{
    return a<b?a:b;
}

int minPathSum(int **grid, int gridRowSize,int gridColSize)
{
    int i, j;
    int *dp = malloc(gridRowSize*sizeof(int *));
    for(i = 0; i < gridRowSize; i++){
        dp[i] = malloc(gridColSize * sizeof(int));
    }

    dp[0][0] = grid[0][0];
    int sum = dp[0][0];
    for(i = 1; i < gridRowSize; i++) {
        sum += grid[i][0];
        dp[i][0] = sum;
    }

    sum = dp[0][0];
    for(i = 1; i < gridColSize; i++) {
        sum += grid[0][i];
        dp[0][i] = sum;
    }

    for(i = 1; i < gridRowSize; i++){
        for(j = 1; j < gridColSize; j++) {
            dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[gridRowSize - 1][gridColSize - 1];
}
