#include <stdio.h>
#include <stdlib.h>


static int** generate(int numRows, int **columnSizes) 
{
    int i, j;
    int **triangle = malloc(numRows * sizeof(int *));
    *columnSizes = malloc(numRows * sizeof(int *));

    for(i=0; i<numRows; i++) {
        int num = i+1;
        (*columnSizes)[i] = num;
        triangle[i] = malloc(num * sizeof(int));
        triangle[i][0] = 1;
        triangle[i][num-1]=1;
        for(j=1; j<=num-2;j++) {
            triangle[i][j] = triangle[i-1][j-1]+triangle[i-1][j];
        }
    }
    return triangle;
}

int main(int argc, char** argv)
{
    int i, j, *sizes, row = atoi(argv[1]);
    int **triangle = generate(row, &sizes);
    for(i=0;i<row;i++) {
        for(j=0;j<sizes[i];j++){
            printf("%d",triangle[i][j]);
        }
        printf("\n");
    }
    return 0;
}
