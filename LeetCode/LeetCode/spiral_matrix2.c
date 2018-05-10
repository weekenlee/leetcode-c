#include <stdio.h>
#include <stdlib.h>

static int** generateMatrix(int n) {
	int i;
	int **matrix = malloc(n * sizeof(int *));
	int *nums = malloc(n * n * sizeof(int));
	for (i = 0; i < n; i++) {
        matrix[i] = &nums[i * n];
	}
}