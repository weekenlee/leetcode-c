#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

static void dfs(int *nums, int size, int start,
	int target, int *stack, int len,
	int **results, int *column_sizes,
	int *count)
{
	int i;
	if (target == 0) {
		results[*count] = malloc(len * sizeof(int));
		memcpy(results[*count], stack, len * sizeof(int));
		column_sizes[*count] = len;
		(*count)++;
	}
	else if (target > 0) {
		for (i = start; i < size; i++) {
			if (i > 0 && nums[i] == nums[i - 1]) {
				continue;
			}
			stack[len] = nums[i];
			dfs(nums, size, i, target - nums[i], stack,
				len + 1, results, column_sizes, count);
		}
	}
}


static int** combinationSum(int* candidates, int candidatesSize
	, int target, int **columnSizes, int* returnSize)
{
	int cap = 100;
	int *stack = malloc(target * sizeof(int));
	int **results = malloc(cap * sizeof(int*));
	*columnSizes = malloc(cap * sizeof(int));
	*returnSize = 0;
	dfs(candidates, candidatesSize, 0, target, stack, 0, results, *columnSizes, returnSize);
	return results;
}



static int compare(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}

static void dfs2(int *nums, int size, int start, int target,
	int *solution, int len, bool *used, int **results, int *column_sizes,
	int *count)
{
	int i;
	if (target == 0) {
		results[*count] = malloc(len * sizeof(int));
		memcpy(results[*count], solution, len * sizeof(int));
		column_sizes[*count] = len;
		(*count)++;
	}
	else if (target > 0) {
		for (i = start; i < size; i++) {
			if (!used[i]) {
				if (i > 0 && !used[i - 1] && nums[i - 1] == nums[i])
					continue;
				used[i] = true;
				solution[len] = nums[i];
				dfs2(nums, size, i + 1, target - nums[i], solution, len + 1,
					used, results, column_sizes, count);
				used[i] = false;
			}
		}
	}
}


static int ** combinationSum2(int *candidates, int candidatesSize,
	int target, int **columnSizes, int* returnSize)
{
	qsort(candidates, candidatesSize, sizeof(int), compare);

	int *solution = malloc(target * sizeof(int));
	int **results = malloc(100 * sizeof(int *));
	bool *used = malloc(candidatesSize);
	memset(used, false, candidatesSize);
	*columnSizes = malloc(100 * sizeof(int));
	*returnSize = 0;
	dfs2(candidates, candidatesSize, 0, target, solution, 0, used, results, *columnSizes, returnSize);
	return results;
}

int main(int argc, char **argv)
{

	int i, j, count = 0;
	int target = 5;
	int *nums = malloc((10 - 2) * sizeof(int));
	for (i = 0; i < 10 - 2; i++) {
		nums[i] = i+1;
	}

	printf("可重复\n");
	int *sizes;
	int **lists = combinationSum(nums, 5 - 2, target, &sizes, &count);
	for (i = 0; i < count; i++) {
		for (j = 0; j < sizes[i]; j++) {
			printf("%d ", lists[i][j]);
		}
		printf("\n");
	}

	printf("无重复\n");
	int *sizes2;
	int **lists2 = combinationSum2(nums, 5 - 2, target, &sizes2, &count);
	for (i = 0; i < count; i++) {
		for (j = 0; j < sizes2[i]; j++) {
			printf("%d ", lists2[i][j]);
		}
		printf("\n");
	}

	getchar();
	return 0;
}