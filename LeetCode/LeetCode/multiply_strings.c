#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void reverse(char *s, int len)
{
	int low = 0;
	int high = len - 1;
	while (low < high) {
		char  c = s[low];
		s[low] = s[high];
		s[high] = c;
		low++;
		high--;
	}
}

static char * multiply(char* num1, char *num2) 
{
	if (*num1 == '\0') {
		return num1;
	}
	if (*num2 == '\0') {
		return num2;
	}

	int i, j;
	char *result = malloc(110 + 110);
	memset(result, '0', 220);
	int len1 = strlen(num1);
	int len2 = strlen(num2);
	reverse(num1, len1);
	reverse(num2, len2);
	for (i = 0; i < len1; i++) {
		int carry = 0;
		for (j = 0; j < len2; j++) {
			carry += (num1[i] - '0')*(num2[j] - '0') + (result[i + j] - '0');
			result[i + j] = carry % 10 + '0';
			carry /= 10;
		}
		if (carry != 0) {
			result[len2 + i] = carry + '0';
		}
	}
	int len = 220;
	while (--len >= 0) {
		if (result[len] > '0') {
			result[++len] = '\0';
			break;
		}
	}
	if (len == -1) {
		len = 1;
		result[len] = '\0';
	}

	reverse(result, len);
	return result;
}

int main(int argc, char **argv)
{
	char *num1 = malloc(4*sizeof(char));
	num1[0] = '1';
	num1[1] = '2';
	num1[2] = '3';
	num1[3] = '\0';
	char *num2 = malloc(4 * sizeof(char));
	num2[0] = '4';
	num2[1] = '5';
	num2[2] = '6';
	num2[3] = '\0';
	printf("%s\n", multiply(num1, num2));
	getchar();
	return 0;
}
