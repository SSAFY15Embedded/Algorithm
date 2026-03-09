/* [1522] 문자열 교환

* 문제 설명:
- a와 b로만 이루어진 문자열이 주어질 때 a를 모두 연속으로 만들고자 함

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char s[1001];
	char copy[2001];
	int i, j;
	int a_count = 0, b_count = 0, minExchange = 1000;

	scanf("%s", s);

	for (i = 0; s[i] != '\0'; i++)
		if (s[i] == 'a')
			a_count++;

	strcpy(copy, s);   
	strcat(copy, s);

	for (i = 0; i < strlen(copy) - a_count; i++) {
		for (j = 0; j < a_count; j++)
			if (copy[i + j] == 'b')
				b_count++;
		if (minExchange > b_count)
			minExchange = b_count;
		b_count = 0;
	}
	
	printf("%d\n", minExchange);
}
