#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int static reverse(int x)
{
	int y = 0;
	while (x) {
		y = y * 10 + x % 10;
		x = x / 10;
	}
	return y;
}

static bool isPalindrome(int x)
{
	if (x == 0) {
		return true;
	}
	if (x < 0) {
		return false;
	}
	return x == reverse(x);
}


static bool isPalindrome2(int x)
{
	if (x == 0) {
		return true;
	}
	if (x < 0) {
		return false;
	}
	int len = 1;
	while (x / len >= 10)
		len *= 10;

	while (x > 0) {
		int left = x / len;
		int right = x % 10;

		if (left != right)
			return false;
		else {
			x = (x % len) / 10;
			len /= 100;
		}
	}
	return true;
}


int main()
{
	printf("%s\n", isPalindrome(atoi("123321")) ? "true" : "false");
	printf("%s\n", isPalindrome2(atoi("123321")) ? "true" : "false");
	return 0;
}
