#include <stdio.h>
#include <stdlib.h>

static inline int mymax(int a, int b)
{
	return a > b ? a : b;
}

static int jump(int* nums, int numsSize)
{
	int i, lo = 0, hi = 0;
	int steps = 0;
	while (hi < numsSize - 1) {
		int right = 0;
		for (i = lo; i <= hi; i++) {
			right = mymax(i + nums[i], right);
		}
		lo = hi + 1;
		hi = right;
		steps++;
	}
	return steps;
}

int main45(int argc, char **argv)
{
	int nums[5] = { 2,3,1,1,4 };
	int count = 5;
	printf("%d\n", jump(nums, count));
	getchar();
	return 0;
}