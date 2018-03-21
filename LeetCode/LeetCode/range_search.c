#include <stdio.h>
#include <stdlib.h>

static int binary_search_start(int *a, int size, int target)
{
	int low = -1;
	int high = size;
	while (low + 1 < high) {
		int mid = low + (high - low) / 2;
		if (target > a[mid]) {
			low = mid;
		}
		else {
			high = mid;
		}
	}

	if (high == size || a[high] != target) {
		return -1;
	}
	else {
		return high;
	}
}

static int binary_search_end(int *a, int size, int target)
{
	int low = -1;
	int high = size;
	while (low + 1 < high) {
		int mid = low + (high - low) / 2;
		if (target < a[mid]) {
			high = mid;
		}
		else {
			low = mid;
		}
	}

	if (low == -1 || a[low] != target) {
		return -1;
	}
	else {
		return low;
	}
}

static int* searchRange(int *nums, int numsSize, int target, int* returnSize)
{
	int *range = malloc(2 * sizeof(int));
	*returnSize = 2;
	if (numsSize == 0) {
		range[0] = range[1] = -1;
		return range;
	}
	range[0] = binary_search_start(nums, numsSize, target);
	range[1] = binary_search_end(nums, numsSize, target);
	return range;
}

int main()
{
	int nums[7] = { 2,4,4,4,6,8,10 };
	int *count;
	int *range = searchRange(nums, 7, 4, &count);
	printf("%d %d\n", range[0], range[1]);
	getchar();
	return 0;
}