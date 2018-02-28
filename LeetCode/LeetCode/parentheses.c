#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void myhelper(int left, int right, char* path)
{
	if (left == 0 && right == 0)
	{
		printf("%s\n", path);
		return;
	}
	if (left != 0) {
		char *newpath = malloc(sizeof(path) + 1 * sizeof(char));
		memcpy(newpath, path, sizeof(path) + 1 * sizeof(char));
		char *i = newpath;
		while (*i != '\0') i++;
		*i++ = '(';
		*i = '\0';
		myhelper(left - 1, right, newpath);
	}

	if (right != 0 && left < right) {
		char *newpath = malloc(sizeof(path) + 1 * sizeof(char));
		memcpy(newpath, path, sizeof(path) + 1 * sizeof(char));
		char *i = newpath;
		while (*i != '\0') i++;
		*i++ = ')';
		*i = '\0';
		myhelper(left, right - 1, newpath);
	}

}
void generateParenthesis2(int n)
{
	char *path = malloc((2 * n + 1) * sizeof(char));
	myhelper(n, n, path);
	return;
}


static char ** generateParenthesis(int n, int* returnSize)
{
	int left, right, cap = 5000, count = 0;
	char *stack = malloc(2 * n + 1);
	char **parentheses = malloc(cap * sizeof(char*));

	char *p = stack;
	left = right = 0;
	stack[2 * n] = '\0';

	while (p != stack || count == 0) {
		if (left == n && right == n) {
			parentheses[count] = malloc(2 * n + 1);
			strcpy(parentheses[count], stack);
			count++;

			while (--p != stack) {
				if (*p == '(') {
					if (--left > right) {
						*p++ = ')';
						right++;
						break;
					}
				}
				else {
					right--;
				}
			}
		}
		else {
			while (left < n) {
				*p++ = '(';
				left++;
			}
			while (right < n) {
				*p++ = ')';
				right++;
			}
		}
	}
	*returnSize = count;
	return parentheses;
}

int main(int argc, char **argv)
{
	int i, count;

	printf("解法1:\n");
	char ** lists = generateParenthesis(5, &count);
	for (i = 0; i < count; i++) {
		printf("%s\n", lists[i]);
	}
	printf("解法2:\n");
	generateParenthesis2(5);
	return 0;
}
