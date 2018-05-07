#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Interval
{
	int start;
	int end;
};

static int binary_search(int *nums, int size, int target)
{
	int low = -1;
	int high = size;
	while(low + 1 < high) {
		int mid  = low + (high - low)/2;
		if(target > nums[mid]) {
			low = mid;
		}else{
			high = mid;
		}
	}

	if (high == size || nums[high] != target) {
		return -high -1;
	}else {
		return high;
	}
}

static struct Interval* insert(struct Interval * intervals, int intervalsSize, 
	struct Interval newInterval, int *returnSize)
{
	struct Interval *p;
	if (intervalsSize == 0) {	
		p = malloc(size(*p));
		p->start = newInterval.start;
		p->end = newInterval.end;
		*returnSize = 1;
		return p;
	}

	int i, count;
	int *nums = malloc(2*intervalsSize*sizeof(int));
	for (i = 0; i < intervalsSize; ++i) {
		nums[i*2] = intervals[i].start;
		nums[i*2 + 1] = intervals[i].end;
	}

	int start0 = binary_search(nums, 2 * intervalsSize, newInterval.start);
	int end0 = binary_search(nums, 2 * intervalsSize, newInterval.end);

	int start1 = -1, end1 = -1;
	int merge_start = -1, merge_end = -1;
	if(start0 >= 0) {
		merge_start = start0/2;
	} else {
		start1 = -start0 - 1;
		merge_start = start1 /2 ;
	}

	if (end0 >= 0) {
		merge_end = end0 /2;
	}else {
		end1 = -end0 - 1;
		if(end1 %2 == 0) {
			merge_end = end1 /2 >0?end1/2-1:0;
		}else{
			merge_end = end1/2;
		}
	}

	if (merge_start == merge_end) {
		if (start0<0 && end0 < 0 && start1 == end1 && start1 % 2 == 0) {
			count = intervalsSize + 1;
			p = malloc(count * sizeof(*p));
			memcpy(p, intervals, merge_start*sizeof(*p));
			p[merge_start] = newInterval;
			memcpy(p + merge_start + 1, intervals+merge_start,(intervalsSize- merge_start)*sizeof(*p));
		}else{
			
		}
	}
}