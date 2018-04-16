#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

static void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

static int compare(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

static void dfs(int *nums, int size, int start, int **result, int *count)
{
	int i;
	if (start == size) {
		result[*count] = malloc(size * sizeof(int));
		memcpy(result[*count], nums, size * sizeof(int));
		(*count)++;
	}
	else {
		for (i = start; i < size; i++) {
			swap(nums + start, nums + i);
			dfs(nums, size, start + 1, result, count);
			swap(nums + start, nums + i);
		}
	}
}

static int **permute(int* nums, int numsSize, int * returnSize)
{
	int count = 0, cap = 5000;
	int **result = malloc(cap * sizeof(int*));
	*returnSize = 0;
	dfs(nums, numsSize, 0, result, returnSize);
	return result;
}
static void dfs2(int *nums, int size, int *stack, int len,
	bool *used, int **results, int *count) {
	int i;
	if (len == size) {
		results[*count] = malloc(len * sizeof(int));
		memcpy(results[*count], stack, len * sizeof(int));
		(*count)++;
	}
	else {
		for (i = 0; i < size; i++) {
			if (!used[i]) {
				if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
				used[i] = true;
				stack[len] = nums[i];
				dfs2(nums, size, stack, len + 1, used, results, count);
				used[i] = false;
			}
		}
	}
}

static int **permute2(int* nums, int numsSize, int * returnSize)
{
	qsort(nums, numsSize, sizeof(int), compare);
	int count = 0, cap = 10000;
	int *stack = malloc(numsSize * sizeof(int));
	int **result = malloc(cap * sizeof(int*));
	bool *used = malloc(numsSize);
	memset(used, false, numsSize);
	*returnSize = 0;
	dfs2(nums, numsSize, stack, 0, used, result, returnSize);
	return result;
}

int main(int argc, char **argv)
{
	int nums[2] = { 1,2 };
	int count = 2;

	int **lists = permute(nums, 2, &count);
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < 2; j++) {
			printf("%d", lists[i][j]);
		}
		putchar('\n');
	}

	putchar('\n');
	int nums2[3] = { 1,1,2 };
	int count2 = 3;

	int **lists2 = permute2(nums2, 3, &count2);
	for (int i = 0; i < count2; i++) {
		for (int j = 0; j < count2; j++) {
			printf("%d", lists2[i][j]);
		}
		putchar('\n');
	}

	getchar();
	return 0;
}