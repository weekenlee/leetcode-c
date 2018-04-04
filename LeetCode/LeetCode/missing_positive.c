#include<stdio.h>
#include<stdlib.h>

static inline void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

static int firstMissingPositive(int *nums, int numsSize)
{
	if(numsSize < 1) {
		return 1;
	}
	int i = 0;
	while (i < numsSize) {
		if (nums[i] != i + 1 && 
			nums[i] > 0 && 
			nums[i] <= numsSize && 
			nums[i] != nums[nums[i] - 1]) {
			swap(nums + i, nums + nums[i] - 1);
		}
		else {
			i++;
		}
	}
	for (i = 0; i < numsSize; i++) {
		if (nums[i] != i + 1) break;
	}
	return i + 1;
}

int main41(int argc, char **argv)
{
	int i, count = 6;
	int nums[6] = { 1,2,3,4,5,7 };
	printf("%d\n", firstMissingPositive(nums, count));
	getchar();
	return 0;
}