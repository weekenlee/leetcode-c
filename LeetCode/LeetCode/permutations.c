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

static int **permute(int* nums, int numsSize, int * returnSize)
{
	int count = 0, cap = 5000;
	int **result = malloc(cap * sizeof(int*));
	*returnSize = 0;
	dfs(nums, numsSize, 0, result, returnSize);
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
	getchar();
	return 0;
}