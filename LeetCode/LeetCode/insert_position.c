#include<stdlib.h>
#include<stdio.h>

static int searchInsert(int *nums, int numsSize, int target)
{
	int low = -1;
	int high = numsSize;
	while (low + 1 < high) {
		int mid = low + (high - low) / 2;
		if (target > nums[mid]) {
			low = mid;
		}
		else {
			high = mid;
		}
	}
	return high;
}

int main35()
{
	int nums[7] = { 2,4,4,4,6,8,10 };
	int *count;
	int n = searchInsert(nums, 7, 3);
	printf("%d \n", n);
	getchar();
	return 0;
}