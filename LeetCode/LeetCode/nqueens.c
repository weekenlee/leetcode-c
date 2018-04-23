#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

static inline int conflict(int *stack, int i, int j)
{
	int k;
	for(k=0;k<i;k++) {
		if(j == stack[k] || abs(i - k) == abs (j - stack[k])) {
			return 1;
		}
	}
	return 0;
}

static inline void push(int *stack, int row, int col)
{
	stack[row] = col;
}

static inline int pop(int *stack, int row)
{
	int col = stack[row];
	stack[row] = -1;
	return col;
}

static inline int top(int *stack, int n)
{
	int row;
	for(row = n - 1; row >= 0; row--) {
		if(stack[row] != -1) {
			return row;
		}
	}
	return 0;
}

static char **solutions(int *stack, int n)
{
	int row, col;
	char **solution = malloc(n*sizeof(char *));

	for (row = 0; row < n; row++)
	{
		char *line = malloc(n+1);
		for(col =0; col <n; col++) {
			line[col] = col ==stack[row]?'Q':'.';
		}
		line[n] = '\0';
		solution[row] = line;
	}
	return solution;

}

char** solveNQueens(int n , int *returnSize) {

}