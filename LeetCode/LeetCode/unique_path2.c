#include<stdio.h>
#include<stdlib.h>

static int uniquePathsWithObstacles(int **obstacleGrid,
                                    int obstacleGridRowSize,
                                    int obstacleGridColSize)
{
    int row, col;
    int reset = 0;
    for(rpw = 0; row < obstacleGridRowSize; row++) {
        if(reset){
            obstacleGrid[row][0] = 1;
        }else {
            if(obstacleGrid[row][0] == 1) {
                reset = 1;
            }
        }
    }

    reset = 0;
    for(col = 0; col < obstacleGridColSize; col++) {
        if(reset){
            obstacleGrid[0][col] = 1;
        }else {
            if(obstacleGrid[0][col] == 1) {
                reset = 1;
            }
        }
    }

    for(row = 0; row < obstacleGridRowSize; row++) {
        int *line = obstacleGrid[row];
        for(col = 0; col < obstacleGridColSize; col ++) }{
            line[col] ^= 1;
        }
    }
}
