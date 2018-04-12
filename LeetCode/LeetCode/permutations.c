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

static int **permute(int* nums)