#include<stdio.h>
#include<stdlib.h>

static int largestRectangleArea(int *hegihts, int hegihtsSize)
{
    int *indexes = (int*)malloc(hegihtsSize * sizeof(int));
    int *left = (int*)malloc(hegihtsSize *sizeof(int));
    int *right = (int*)malloc(hegihtsSize *sizeof(int));

    int i, pos  = 0;
    for(i = 0; i<hegihtsSize; i++){
        while(pos>0 && hegihts[indexes[pos - 1]] >= hegihts[i]) {
            pos--;
        }
        left[i] = pos == 0 ? -1 : indexes[pos -1];
        indexes[pos++] = i;
    }

    pos = 0;
    for(i = hegihtsSize -1 ; i>=0; i--) {
        while(pos > 0 && hegihts[indexes[pos-1]] >= hegihts[i]) {
            pos--;
        }
        right[i] = pos == 0 ? hegihtsSize:indexes[pos -1];
        indexes[pos++] = i;
    }

    int max_area = 0;
    for(i = 0; i< hegihtsSize; i++) {
        int area = hegihts[i]*(right[i] - left[i] - 1);
        max_area = area > max_area ? area : max_area;
    }
    return max_area;
}

int main(void)
{
    int nums[]={2,1,5,6,2,3};
    int count = sizeof(nums) / sizeof(*nums);
    printf("%d\n",largestRectangleArea(nums, count) );
    return 0;
}
