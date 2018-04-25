#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

static int partition(int *nums, int lo, int hi)
{
	if(lo == hi) {
		return nums[lo];
	}

	int ce = (hi - lo) / 2;
	int left_max = partition(nums, lo, lo + ce);
	int right_max = partition(nums, hi - ce, hi);

	int i;
	int left_border = 0, left_border_max = INT_MIN;
	for (i = ce; i >= lo; i--)
	{
		left_border += nums[i];
		if(left_border > left_border_max) {
			left_border_max = left_border;
		}
	}

	int right_boarder = 0, right_boarder_max = INT_MIN;
	for(i = ce + 1; i <= hi; i++) {
		right_boarder += nums[i];
		if(right_boarder > right_boarder_max) {
			right_boarder_max = right_boarder;
		}
	}

	int sum = left_border_max + right_boarder_max;
	int max = left_max > right_max ? left_max: right_max;
	return sum > max ? sum:max;
}

/*
利用动态规划思想，sum[i]表示以A[i]结尾的最大连续子数组和。好，那么sum[i]什么时候最大？sum[i] = max(sum[i-1]+A[i],A[i])。
再进一步化简的话，就是sum[i-1]是否小于0，当小于0时，sum[i] = A[i]。也就是求出的sum[i]一定包含A[i]的值。
*/
static int maxSubArray(int *nums, int numsSize)
{
	#if 1
		int i, len = 0 , max = INT_MIN;
		for(i = 0; i< numsSize; i++) {
			len += nums[i];
			max = len> max?len:max;
			if(len<0) {
				len = 0;
			}
		}
		return max;
	#else
		return partitions(nums, 0, numsSize -1);
	#endif
}


int main(int argc, char **argv)
{
    int nums[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    printf("%d\n", maxSubArray(nums, sizeof(nums) / sizeof(*nums)));
    return 0;
}

