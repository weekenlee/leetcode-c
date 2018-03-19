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



//���ȣ�����β�˿�ʼ��ǰѰ���������ڵ�Ԫ�أ����һ��Ԫ���� i���ڶ���Ԫ���� ii�������� i<ii ��
//Ȼ���ٴ���β�˿�ʼ��ǰ�������ҳ���һ������ i ��Ԫ�أ�����Ϊ j��
//Ȼ�󣬽� i �� j �Ե����ٽ� ii ������������Ԫ�ط�ת��
static void nextPermutation(int *nums, int numsSize)
{
	if (numsSize <= 1) {
		return;
	}

	int *p = nums + numsSize - 1; //���һ����
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