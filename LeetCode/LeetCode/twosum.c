#include <stdio.h>
#include <stdlib.h>

struct object {
	int val;
	int index;
};

static int compare(const void* a, const void* b)
{
	return ((struct object*)a)->val - ((struct object*)b)->val;
}

static int* twosum(int *nums, int numsize, int target)
{
	int i, j;
	struct object *objs = (struct object *)malloc(numsize * sizeof(*objs));
	for (i = 0; i < numsize; i++) {
		objs[i].val = nums[i];
		objs[i].index = i;
	}
	qsort(objs, numsize, sizeof(*objs), compare);

	int *results = (int *)malloc(2 * sizeof(int));
	i = 0;
	j = numsize - 1;
	while (i < j) {
		int diff = target - objs[i].val;
		if (diff > objs[j].val) {
			while (++i < j && objs[i].val == objs[i - 1].val) {}
		}
		else if (diff < objs[j].val) {
			while (--j > i && objs[j].val == objs[j + 1].val) {}
		}
		else {
			results[0] = objs[i].index;
			results[1] = objs[j].index;
			return results;
		}
	}
	return NULL;
}

int main(void)
{
	int nums[] = { 3, 2, 3 };
	int count = sizeof(nums) / sizeof(*nums);
	int target = 6;
	int *indexes = twosum(nums, count, target);
	if (indexes != NULL) {
		printf("%d %d\n", indexes[0], indexes[1]);
	}
	else {
		printf("Not found\n");
	}
	return 0;
}
