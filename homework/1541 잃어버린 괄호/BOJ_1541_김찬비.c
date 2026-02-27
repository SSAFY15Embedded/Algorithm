#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	char s[100];
	int i, temp = 0, total = 0, flag = 0;

	scanf("%s", s);

	for (i = 0; s[i] != '\0'; i++) {
		if (s[i] == '+') {
			if(flag)
				total -= temp;
			else
				total += temp;
			temp = 0;
		}
		else if (s[i] == '-') {
			if (flag)
				total -= temp;
			else
				total += temp;
			temp = 0;
			flag = 1;
		}
		else
			temp = temp * 10 + (s[i] - '0');
	}
	if (flag)
		total -= temp;
	else
		total += temp;

	printf("%d\n", total);
}
