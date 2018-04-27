#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*

given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.

DP：局部最优和全局最优解法
复杂度：O（N）

    维护两个变量
    全局最优：到目前为止能跳到的最远距离
    局部最优：从当前一步出发能跳到的最远距离
    local[i]=A[i]+i
    global[i]=max(global[i],local[i])
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;
        int reach=0;
        for(int i=0;i<=reach && i<n;i++){
            reach=max(nums[i]+i,reach);
        }

        if(reach<n-1)
            return false;
        return true;
    }
};

贪心：O（N）

    跳到位置i

后，可以达到的最大距离至少是i+A[i]
记录当前能达到的最远距离maxIndex

    能跳到的位置 i

的条件是: i<=maxIndex
一旦跳到i
,则maxIndex=max(maxIndex,i+A[i])
能跳到最后一个位置 n−1
的条件是maxindex>=n-1

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxIndex=0;
        for(int i=0;i<n;i++){
            if(i>maxIndex || maxIndex>=(n-1))
                break;
            maxIndex=max(maxIndex,i+nums[i]);
        }

        return maxIndex>=(n-1)? true:false;
    }
};
*/

static inline int max(int a, int b)
{
	return a > b ? a : b;
}

static bool canJump(int *nums, int numsSize)
{
	int i, pos = 0;
	for(i = 0; i < numsSize - 1; i++) {
		if(pos < i || pos >= numsSize -1) {
			break;
		}
		pos = max(i + nums[i], pos);
	}
	return pos >= numsSize - 1;
}

int main(int argc, char **argv)
{
	int i, count = argc -1;
	int *nums = malloc(count * sizeof(int));
	 for (i = 0; i < count; i++) {
        nums[i] = atoi(argv[i + 1]);
    }
    printf("%s\n", canJump(nums, count) ? "true" : "false");
	return 0;
}