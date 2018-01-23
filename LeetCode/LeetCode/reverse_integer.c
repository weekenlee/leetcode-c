#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


static int reverse(int x)
{
	int y = 0;
	while (x != 0) {
		int n = x % 10;
		if (y > INT_MAX / 10 || y < INT_MIN / 10) {
			return 0;
		}
		y = y * 10 + n;
		x /= 10;
	}
	return y;
}

#define TEST(n, e) printf("%12d  =>  %-12d  %s!\n", n, reverse(n), e == reverse(n)?"passed":"failed")


int main(int argc, char**argv)
{
	//basic cases
	TEST(123, 321);
	TEST(-123, -321);
	TEST(-100, -1);
	TEST(1002, 2001);
	//big integer
	TEST(1463847412, 2147483641);
	TEST(-2147447412, -2147447412);
	TEST(2147447412, 2147447412);
	//overflow
	TEST(1000000003, 0);
	TEST(2147483647, 0);
//	TEST(-2147483648, 0);
	//customized cases
	int n = atoi("123123");
	printf("%12d  =>  %-12d  %s!\n", n, reverse(n), reverse(reverse(n)) == n ? "passed" : "failed");
	char c = getchar();
	return 0;
}