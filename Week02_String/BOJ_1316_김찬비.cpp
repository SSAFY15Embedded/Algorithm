#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int is_in(char s[], char c) {
	int i;
	for (i = 0; s[i] != '\0'; i++)
		if (s[i] == c)
			return 1;
	return 0;
}

int isGroupWord(char s[]) {
	int i, j = 0;
	char word[100];
	for (i = 1; s[i] != '\0'; i++) 
		if (s[i - 1] != s[i]) {
			word[j++] = s[i - 1];
			word[j] = '\0';
			if (is_in(word, s[i]))
				return 0;
		}
	return 1;
}

int main(void) {
	int n, i;
	char s[100];
	int count = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%s", s);
		if (isGroupWord(s))
			count++;
	}
	printf("%d", count);
}
