#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

static char *minWindow(char *s, char *t)
{
    int i, f[256], m[256], pat_len = 0;
    memset(m, 0, sizeof(m));
    memset(f, 0, sizeof(f));

    for(i = 0; t[i] != '\0'; i++) {
        m[t[i]]++;
        pat_len++;
    }

    int start = -1;
    int size = INT_MAX;
    int found = 0;
    int begin = 0;
    for(i = 0;s[i]!='\0'; i++) {
        if(m[s[i]] >0){
            if(++f[s[i]] <= m[s[i]]){
                found++;
            }
        

            if(found == pat_len) {
                while(m[s[begin]] == 0 || f[s[begin]] > m[s[begin]]) {
                    if(f[s[begin]] > m[s[begin]]) {
                        f[s[begin]]--;
                    }
                    begin++;
                }

                if(size>i-begin + 1) {
                    start = begin;
                    size = i - begin + 1;
                }
            }
        }
    }

    char *result;
    if(start >= 0 && size > 0) {
        result = malloc(size +1);
        memcpy(result, s + start, size);
        result[size] = '\0';
    }else{
        result = malloc(1);
        result[0] = '\0';
    }
    return result;
}

int main(int argc, char **argv)
{
    printf("Answer: %s\n", minWindow(argv[1], argv[2]));
    return 0;
}
