#include<stdio.h>
#include<stdlib.h>
#include<string.h>

static void
line_fill(char *line,
          int len,
          char **words,
          int *word_lens,
          int max_size,
          int even_spaces,
          int remain_spaces,
          int start,
          int end)
{
    int i,j;
    char *p = line;
    for(i = start; i < end; i++) {
        memcpy(p, words[i], word_lens[i]);
        p += word_lens[i];
        if(i < end - 1) {
            for(j = 0; j < even_spaces; j++) {
                *p++ = ' ';
            }
            if(remain_spaces > 0) {
                *p++ = ' ';
                remain_spaces--;
            }
        }
    }
    while(p - line < max_size) {
        *p-- = ' ';
    }
    *p++ = '\0';
}

static char**
fullJustify(char** words,
            int wordSize,
            int maxWidth,
            int *returnSize)
{
    int i, j, k, cap = 100, count = 0;
    char **lines = malloc(cap *sizeof(char *));
    char *buf = malloc(cap *(maxWidth + 1));
}
