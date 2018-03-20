#include<stdio.h>
#include<stdlib.h>

static int binary_search(int *nums, int size, int target)
{
	int low = -1;
	int high = size;

	while (low + 1 < high) {
		int mid = low + (high - low) / 2;
		if (target > nums[mid]) {
			low = mid;
		}
		else {
			high = mid;
		}
	}

	if (high == size || nums[high] != target) {
		return -1;
	}
	else {
		return high;
	}
}


static int start_find(int *nums, int size) 
{
	int low = 0;
	int high = size - 1;
	while (low < high && nums[low] > nums[high]) {
		int mid = low + (high - low) / 2;
		if (nums[mid] > nums[high]) {
			low = mid + 1;
		}
		else if (nums[mid] < nums[low]) {
			high = mid;
		}
	}
	return low;
}

static int search(int *nums, int numsSize, int target)
{
	if (numsSize <= 0) {
		return -1;
	}
	if (numsSize == 1) {
		return target == nums[0] ? 0 : -1;
	}

	int i = start_find(nums, numsSize);
	if (i == 0) {
		return binary_search(nums, numsSize, target);
	}
	else if (target >= nums[0]) {
		return binary_search(nums, i, target);
	}
	else if (target <= nums[numsSize - 1]) {
		int index = binary_search(nums + i, numsSize - i, target);
		return index >= 0 ? index + i : -1;
	}
	else {
		return -1;
	}
}


int main()
{
	int i;
	int nums[6]= { 4,5,6,1,2,3 };
	printf("%d\n", search(nums, 6, 6));
	getchar();
	return 0;
}