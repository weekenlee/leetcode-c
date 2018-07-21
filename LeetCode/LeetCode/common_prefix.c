#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static char* longestCommonPrefix(char** strs, int strSize)
{
	int i, count = 0;
	char *result = (char *)malloc(100);
	while (strSize > 0) {
		char c = strs[0][count];
		for(i=1;i<strSize;i++)  {
			if (c != strs[i][count]) break;
		}
		if (i == strSize && c != '\0') {
			result[count++] = c;
		}
		else {
			break;
		}
	}

	result[count++] = '\0';
	return result;
}

int main(int argc, char **argv)
{
	char *s[] = { "abcdef", "abc", "abc"};
	printf("%s\n", longestCommonPrefix(s, 3));
	return 0;
}
