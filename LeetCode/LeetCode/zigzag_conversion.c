#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char * convert(char *s, int numRows) {
	if (numRows <= 1) return s;

	int len = strlen(s);
	char *newstr = malloc(len + 1);
	char *p = newstr;
	int row = 0;

	for (row = 0; row < numRows; row++) {
		int interval1 = numRows + (numRows - 2) - row * 2;
		int interval2 = 2 * row;
		int flag = 0;
		int i = row;
		while (i < len) {
			*p++ = s[i];
			int delta = 0;
			do {
				delta = flag == 0 ? interval1 : interval2;
				flag = !flag;
			} while (delta == 0);
			i += delta;
		}
	}

	newstr[len] = '\0';
	return newstr;
}

int main(int argc, char **argv)
{

	printf("%s\n", convert("PAYPALISHIRING", 3));
	char c = getchar();
	return 0;
}