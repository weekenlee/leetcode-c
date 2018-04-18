#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct word_hash {
	char *word;
	int num;
	int indexes[10];
};

static int compare(const void *a, const void *b)
{
	return *(char*)a - *(char*)b;
}

static inline int BKDRHash(char *s, size_t size)
{
	int seed = 31;
	unsigned long hash = 0;
	while(*s != '\0') {
		hash = hash *seed + *s++;
	}
	return hash % size;
}

static char *** groupAnagrams(char ** strs, int strSize, int** columnSize, int* returnSize)
{
	int i, j, count = 0;
	int hash_size = strSize;

}