#include<stdio.h>
#include<stdlib.h>
#include<string.h>

static char* simplifyPath(char *path)
{
    int len = strlen(path);
    if(len == 0){
        return path;
    }
    char *p = path;
    int *indexes = malloc(len * sizeof(int));
    int depth = 0;
    int name_start = 1;
    while(*p != '\0') {

    }
}
