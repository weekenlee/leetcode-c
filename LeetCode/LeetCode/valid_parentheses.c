#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

static bool isValid(char *s)
{
	int n = 0, cap = 100;
	char *stack = malloc(cap);

	while (*s != '\0') {
		switch (*s)
		{
		case '(':
		case '[':
		case '{':
			if (n + 1 >= cap) {
				cap *= 2;
				stack = realloc(stack, cap);
			}
			stack[n++] = *s;
			break;
		case ')':
			if (stack[--n] != '(') return false;
			break;
		case ']':
			if (stack[--n] != '[') return false;
			break;
		case '}':
			if (stack[--n] != '{') return false;
			break;
		default:
			return false;
		}
		s++;
	}
}

int main(int argc, char **argv)
{

	printf("%s\n", isValid("()[{}]") ? "true" : "false");
	char c = getchar();
	return 0;
}