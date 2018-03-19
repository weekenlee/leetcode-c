#include<stdio.h>
#include<stdlib.h>

static void reverse(int *a, int size)
{
	int left = 0;
	int right = size - 1;
	while (left < right) {
		int tmp = a[left];
		a[left] = a[right];
		a[right] = tmp;
		left++;
		right--;
	}
}



//首先，从最尾端开始往前寻找两个相邻的元素，令第一个元素是 i，第二个元素是 ii，且满足 i<ii ；
//然后，再从最尾端开始往前搜索，找出第一个大于 i 的元素，设其为 j；
//然后，将 i 和 j 对调，再将 ii 及其后面的所有元素反转。
static void nextPermutation(int *nums, int numsSize)
{
	if (numsSize <= 1) {
		return;
	}

	int *p = nums + numsSize - 1; //最后一个数
	int *q = nums + numsSize - 1;
	
	while (p != nums && *(p - 1) >= *p) {
		p--;
	}

	if (p != nums) {
		int n = *(p - 1);
		while (*q <= n) {
			q--;
		}

		int tmp = *q;
		*q = *(p - 1);
		*(p - 1) = tmp;
	}
	reverse(p, numsSize - (p - nums));
}

int main31(int argc, char **argv)
{
	
	int i;
	int *nums = malloc(5*sizeof(int));
	for (i = 0; i < 5; i++) {
		nums[i] = i+1;
	}

	nextPermutation(nums, 5);

	for (i = 0; i < 5; i++) {
		printf("%d", nums[i]);
	}
	putchar('\n');
	getchar();
	return 0;
}