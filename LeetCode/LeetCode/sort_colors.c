#include<stdio.h>
#include<stdlib.h>
#include<string.h>

static inline void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

static void sortColors(int *nums, int numsSize)
{
    int i = 0, j = numsSize -1;
    while(i<j){
        while(nums[i] ==0 && j > i) {
            i++;
        }

        while(nums[j] ==0 && j > i) {
            j--;
        }
        swap()
    }
}
