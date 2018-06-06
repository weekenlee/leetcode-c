#include<stdio.h>
#include<stdlib.h>

static void setZeroes(int** matrix, int matrixRowSize, int matrixColSize)
{
    int row, col, bRow = 0, bCol = 0;
    for(row = 0; row < matrixRowSize; row++) {
        for(col = 0; col < matrixColSize; col++) {
            if(matrix[row][col] == 0) {
                if(row == 0) bCol = 1;
                if(col == 0) bRow = 1;
                matrix[0][col] = matrix[row][0] = 0;
            }
        }
    }

    for(row = 1; row < matrixRowSize; row++) {
        for(col = 1; col < matrixColSize; col++) {
            if(matrix[0][col] == 0 || matrix[row][0] ==0) {
                matrix[row][col] = 0;
            }
        }
    }

    if(bRow){
        for(row = 0; row < matrixRowSize; row++) {
            matrix[row][0] = 0;
        }
    }

    if(bCol) {
        for(col = 0; col < matrixColSize; col++) {
            matrix[0][col] = 0;
        }
    }
}

int main(int argc, char** argv)
{
    int rowsize = 2;
    int colsize = 2;
    int **a = malloc(rowsize*sizeof(int*));
    for(int i = 0; i < rowsize; i++) {
        int *b = malloc(colsize * sizeof(int));
        for(int j = 0; j < colsize; j++){
            *(b+j) = i;
        }
        *(a+i) = b;
    }
    for(int i = 0; i < rowsize; i++){
        for(int j = 0; j < colsize; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("setZero\n");
    setZeroes(a, rowsize, colsize);
    for(int i = 0; i < rowsize; i++){
        for(int j = 0; j < colsize; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}

