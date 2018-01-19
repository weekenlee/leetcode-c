#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline int minnum(int a, int b)
{
	return a < b ? a : b;
}

static int manacher(char *s, char output[])
{
	int i, j;
	char s2[1000] = { '\0' };
	s2[0] = '$';
	for (i = 0; s[i] != '\0'; i++) {
		s2[(i << 1) + 1] = '#';
		s2[(i << 1) + 2] = s[i];
	}
	s2[(i << 1) + 1] = '#';
	int len = (i << 1) + 2;
	s2[len] = '\0';

	int p[1000] = { 0 };// ��s2ĳһ��Ϊ���ĵĻ��İ뾶
	int id = 0;			// �������ĵ�
	int limit = 0;		// ����ĵ��ұ߽��
	int maxLen = 0;		// �����ĳ���
	int maxId = 0;		// ����ĵ����ĵ�

	for (i = 1; i < len; i++) {
		if (i < limit) {
			p[i] = minnum(p[2 * id - 1], limit - i);
		}
		else {
			p[i] = 1;
		}

		while (s2[i + p[i]] == s2[i - p[i]]) {
			p[i]++;
		}

		if (i + p[i] > limit) {
			limit = i + p[i];
			id = i;
		}
		if (maxLen < p[i] - 1) {
			maxLen = p[i] - 1;
			maxId = i;
		}
	}

	for (j = 0, i = maxId - maxLen; i <= maxId + maxLen; i++) {
		if (s2[i] != '#') {
			output[j++] = s2[i];
		}
	}
	return maxLen;
}

static char *longestPalindrom(char *s)
{
	int i;
	if (s == NULL) {
		return NULL;
	}

	int len = strlen(s);
	if (len <= 1) {
		return s;
	}

	char *palindrome = malloc(1000);
	memset(palindrome, 0, sizeof(palindrome));

	int size = manacher(s, palindrome);
	palindrome[size] = '\0';
	return palindrome;
}


int main()
{
	printf("%s\n", longestPalindrom("abcdeffedcba"));
	char c = getchar();
	return 0;
}
