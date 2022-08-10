#include <stdio.h>

int main() {
    char* a = "a";
    printf("%s\n", a);
    printf("%c\n", a[0]);
    printf("%d\n", (a[0]-0)&0x1);
    printf("%d\n", (a[0]-0)>>1&0x1);
    printf("%d\n", (a[0]-0)>>2&0x1);
    return 0;
}