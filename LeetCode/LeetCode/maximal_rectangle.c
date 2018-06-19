#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

static inline int max(int a, int b) 
{
    return a>b?a:b;
}

static int area_calc（int* heights, int size)
{
    int *indexes = malloc(size*sizeof(int));
    int *left = malloc(size*sizeof(int));
    int *right = malloc(size*sizeof(int));

    int i, pos = 0;
    for(i = 0; i< size; i++) {
        while(pos>0 && height[indexes[pos-1]] >= heights[i]) {
            pos--;
        }
        left[i] = pos == 0 ? -1:indexes[pos-1];
        indexes[pos++] = i;
    }

    pos = 0;
}
