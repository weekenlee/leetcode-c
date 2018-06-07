#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

static int binary_search(int *nums, int len, int target) 
{
    int low = -1;
    int high = len;
    while(low + 1 < high) {
        int mid = low + (high - low)/2;
        if(target > nums[mid]) {
            low = mid;
        }else{
            high = mid;
        }
    }
    if(high == len || nums[high] != target) {
        return -high-1;
    }else{
        return high;
    }
}

