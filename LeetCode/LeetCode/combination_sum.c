#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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