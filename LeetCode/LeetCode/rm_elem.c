#include<stdio.h>
#include<stdlib.h>

static int removeElement(int *nums, int numsSize, int val)
{
	int i, count = 0;
	for (i = 0; i < numsSize; i++) {
		if (nums[i] != val) {
			nums[count++] = nums[i];
		}
	}
	return count;
}

int main()
{
	int i, size = 10;
	int *nums = malloc(size * sizeof(int));
	for (i = 0; i < 10; i++) {
		if (i % 2 == 0) {
			nums[i] = i - 1;
		}
		else {
			nums[i] = i;
		}
	}
	for (i = 0; i < 10; i++) {
		printf("%d ", nums[i]);
	}
	printf("\n");
	int count = removeElement(nums, size, 1);
	for (i = 0; i < count; i++) {
		printf("%d ", nums[i]);
	}
	printf("\n");
	getchar();
	return 0;

}