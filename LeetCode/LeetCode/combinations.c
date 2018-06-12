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
        results[*count] = malloc(k * sizeof(int));
        memcpy(results[*count], stack, k * sizeof(int));
        (*count)++;
    }else{
        for(i = start; i <= n; i++) {
            if(!used[i]) {
                stack[len] = i;
                used[i] = true;
            }
        }
    }
}

int**
combine(int n, int k, int** columnSizes, int* returnSize)
{
    int capacity = 10000;
    int count = 0;
    int **results = malloc(capacity * sizeof(int *));
    int *stack = malloc(k * sizeof(int));
    bool *used = malloc((n+1)*sizeof(bool));
    memset(used, false, n+1);
}
