#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>


static int compare(const void* a, const void *b)
{
	return *(int*)a - *(int*)b;
}

static int threeSumClosest(int *nums, int numSize, int target)
{
	int i, min_diff = INT_MAX;

	if (numSize < 3) {
		return min_diff;
	}

	qsort(nums, numSize, sizeof(*nums), compare);

	for (i = 0; i < numSize; i++) {
		int left = i + 1;
		int right = numSize - 1;
		while (left < right) {
			int diff = nums[i] + nums[left] + nums[right] - target;
			if (abs(diff) < abs(min_diff)) {
				min_diff = diff;
			}
			if (diff < 0) {
				left++;
			}
			else if (diff > 0) {
				right--;
			}
			else {
				return target;
			}
		}
	}
	return min_diff + target;
}

int main(void)
{
	int i, target = 1;
	int nums[] = { -1,2,1,-4 };
	printf("%d\n", threeSumClosest(nums, sizeof(nums) / sizeof(nums[0]), target));
	char c = getchar();
	return 0;
}
