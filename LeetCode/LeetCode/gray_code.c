#include<stdio.h>
#include<stdlib.h>

int *grayCode(int n, int *returnSize) {
    if (n < 0) {
        return NULL;
    }

    int i, count = 1 << n;
    int *codes = malloc(count * sizeof(int));
    for(i = 0; i < count; i++) {
        codes[i] = (i >> 1)^i;
    }

    *returnSize = 1 << n;
    return codes;
}

int main(int argc, char **argv) 
{
    int i, count;
    int *list = grayCode(atoi(argv[1]), &count);
    for(i = 0; i < count; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
    return 0;
}
