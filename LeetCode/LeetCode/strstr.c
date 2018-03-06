#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#if 0

int strStr(char *haystack, char *needle)
{
	if (haystack == NULL || needle == NULL) {
		return -1;
	}

	int hlen = strlen(haystack);
	int nlen = strlen(needle);

	if (hlen < nlen) {
		return -1;
	}

	if (nlen == 0) {
		return 0;
	}

}

#endif

static int strStr(char* haystack, char* needle)
{
	unsigned int hlen = strlen(haystack);
	unsigned int nlen = strlen(needle);

	if (nlen == 0) {
		return 0;
	}

	int i, j;
	for (i = 0; i < hlen; i++) {
		int found = 1;
		if (haystack[i] == needle[0]) {
			for (j = 1; j < nlen; j++) {
				if (i + j < hlen) {
					if (haystack[i + j] != needle[j]) {
						found = 0;
						break;
					}
				}
				else {
					return -1;
				}
			}

			if (found) {
				return i;
			}
		}
	}
	return -1;
}

int main(int argc, char **argv)
{
	printf("%d\n", strStr("abcdefg", "efg"));
	getchar();
	return 0;
}