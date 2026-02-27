#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int A, B, a = 0, b = 0;
	int i = 0;

	scanf("%d %d", &A, &B);
	
	for (i = 0; i < 3; i++) {
		a = a * 10 + (A % 10);
		b = b * 10 + (B % 10);
		A /= 10;
		B /= 10;
	}
	
	if (a > b)
		printf("%d", a);
	else
		printf("%d", b);
}
