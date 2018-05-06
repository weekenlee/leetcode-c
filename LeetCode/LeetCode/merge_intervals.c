#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Interval
{
	int start;
	int end;
};

static int binary_search(int *nums, int size, int target)
{
	int low = -1;
	int high = size;
	while(low + 1 < high) {
		int mid  = low + (high - low)/2;
		if(target > nums[mid]) {
			low = mid;
		}else{
			high = mid;
		}
	}

	if (high == size || nums[high] != target) {
		return -high -1;
	}else {
		return high;
	}
}

static struct Interval* insert(struct Interval * intervals, int )