#include <stdio.h>
#include <stdlib.h>

static int trap(int *height, int heightSize)
{
	if (heightSize < 2) {
		return 0;
	}

	int i, j, top0 = -1, top1 = -1, sum = 0, level = 0;
	for (i = 0; i < heightSize; i++) {
		if (height[i] > 0) {
			top0 = i;
			break;
		}
	}

	while (i < heightSize) {
		top1 = -1;
		for (j = i + 1; j < heightSize; j++) {
			if (top1 < 0 || height[j] >= height[top1]) {
				top1 = j;
			}
			if (height[j] >= height[top0]) {
				break;
			}
		}

		if (top1 >= 0) {
			int level = height[top0] < height[top1] ? height[top0] : height[top1];
			while (i < top1) {
				if (level > height[i]) {
					sum += level - height[i];
				}
				i++;
			}
			top0 = top1;
			i = top1;
		}
		else {
			i = j;
		}
	}

	return sum;
}

int main(int argc, char **argv)
{
	int i, count = 12;
	int nums[12] = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	
	printf("%d\n", trap(nums, count));
	getchar();
	return 0;
}