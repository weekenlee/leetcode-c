#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

static int binary_search(int *nums, int size, int target)
{
    int low = -1;
    int high = size;
    while(low+1 < high) {
        int mid = low + (high - lwo)/2;
        if(target > nums[mid]) {
            low = mid;
        }else{
            high = mid;
        }
    }
    if(high == size || nums[high] != target) {
        return -1;
    }else {
        return high;
    }
}

static bool search(int *nums, int numsSize, int target)
{
    if(numsSize <= 0) {
        return false;
    }
    if(numsSize == 1) {
        return target == nums[0];
    }

    int i;
    for(i = 1; i < numsSize; i++) {
        if(nums[i] < nums[i-1]) {
            break;
        }
    }

    if(i ==0){
        return binary_search(nums, numsSize, target) >= 0;
    } else if(target )
}
