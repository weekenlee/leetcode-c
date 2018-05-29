#include<stdio.h>
#include<stdlib.h>
#include<string.h>

static int *plusOne(int * digits , int digitsSize, int *returnSize)
{
    int i, j, len = 0, carry = 1;
    int *result = malloc((digitsSize + 1)*sizeof(int));
    for(i = digitsSize - 1 ; i >= 0||carry; i--){
        int n = i>=0?digits[i] + carry:carry;
        result[len++] = n % 10;
        carry = n / 10;
    }

    for(i = 0, j = len - 1; i < j; i++, j--){
        int tmp = result[i];
        result[i] = result[j];
        result[j] = tmp;
    }

    *returnSize = len;
    return result;
}

int main(int argc, char** argv)
{
    int i, count = strlen(argv[1]);
    int *digits = malloc(count * sizeof(int));
    for(i = 0;i<count;i++){
        digits[i] = argv[1][i] - '0';
    }

    int len = 0;
    printf("%d, %d", count, len);
    printf("\n");
    int *res = plusOne(digits, count, &len);
    printf("%d, %d", count, len);
    printf("\n");
    for(i = 0; i< len; i++){
        printf("%c", res[i] + '0');
    }
    printf("\n");
    return 0;
}
