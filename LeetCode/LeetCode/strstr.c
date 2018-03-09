#include<stdio.h>
#include<stdlib.h>
#include<string.h>



int strStr2(char *haystack, char *needle)
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

	/* boyer-moore bad character */
	//�����ڲ������ַ������㷨���У�BM��Boyer - Moore���㷨��Ŀǰ����Ϊ���Ч���ַ��������㷨������Bob Boyer��J Strother Moore�����1977�ꡣ һ������£���KMP�㷨��3 - 5�������㷨�������ı��༭���е�����ƥ�书�ܣ�����������֪��GNU grep����ʹ�õľ��Ǹ��㷨����Ҳ��GNU grep��BSD grep���һ����Ҫԭ��
	int i, j;
	int bad_steps[128];
	for (i = 0; i < 128; i++) {
		bad_steps[i] = nlen;
	}

	for (i = 0; i < nlen; i++) {
		bad_steps[needle[i]] = nlen - 1 - i;
	}
	/*boyer-moore good suffix*/
	int *good_steps = malloc(nlen * sizeof(int));
	for(i = 0; i < nlen; i++) {
		good_steps[i] = nlen;
		for (j = i - 1; j >= 0; j--) {
			if (!memcmp(needle + i, needle + j, nlen - i)) {
				good_steps[i] = i - j;
				break;
			}
		}
	}

	char *p = haystack + nlen - 1;
	char *q = needle + nlen - 1;
	char *r = p;
	while (p - haystack < hlen) {
		int step = 0;
		for (i = 1; i <= nlen && *p == *q; i++) {
			if (q == needle) {
				return p - haystack;
			}
			if (good_steps[nlen - i] > step) {
				step = good_steps[nlen - i];
			}
			p--;
			q--;
		}

		if (i == 1 && bad_steps[*p] > step) {
			step = bad_steps[*p];
		}
		r += step;
		p = r;
		q = needle + nlen - 1;
	}
	return -1;
}



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

int main28(int argc, char **argv)
{

	printf("%d\n", strStr("abcdefg", "efg"));
	printf("%d\n", strStr2("abcdefg", "efg"));

	getchar();
	return 0;
}