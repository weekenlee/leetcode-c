//假设有左指针left和右指针right，且left指向的值小于right的值，假如我们将右指针左移，则右指针左移后的值和左指针指向的值相比有三种情况
//
//右指针指向的值大于左指针
//这种情况下，容器的高取决于左指针，但是底变短了，所以容器盛水量一定变小
//右指针指向的值等于左指针
//这种情况下，容器的高取决于左指针，但是底变短了，所以容器盛水量一定变小
//右指针指向的值小于左指针
//这种情况下，容器的高取决于右指针，但是右指针小于左指针，且底也变短了，所以容量盛水量一定变小了
//综上所述，容器高度较大的一侧的移动只会造成容器盛水量减小
//所以应当移动高度较小一侧的指针，并继续遍历，直至两指针相遇。

#include <stdio.h>
#include <stdlib.h>

static int maxArea(int *height, int heightSize)
{
	int min = 0, max = heightSize - 1;
	int area_max = 0;
	while (min < max) {
		int area = (max - min)*(height[min] < height[max] ? height[min] : height[max]);
		area_max = area > area_max ? area : area_max;
		if (height[min] < height[max]) {
			while (++min < max && height[min] <= height[min - 1]) {
				continue;
			}
		}
		else {
			while (min < --max && height[max] <= height[max + 1]) {
				continue;
			}
		}
	}
	return area_max;
}


//int main(int argc, char **argv)
//{
//	int i, count = argc - 1;
//	int *nums = malloc(count * sizeof(int));
//	for (i = 0; i < count; i++) {
//		nums[i] = atoi(argv[i + 1]);
//	}
//	printf("%d\n", maxArea(nums, count));
//	return 0;
//}