#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

static void 
dfs(int n, int k, int *stack, int len, bool *used, int *col_sizes, int **result, int *count)
{
    int i;
    if(len == k) {
        col_sizes[*count] = k;
    }
}
