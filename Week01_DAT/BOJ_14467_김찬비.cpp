#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int N, i, cowN, position;
	int A[11], count = 0;

	scanf("%d", &N);

	for (i = 1; i <= 10; i++)
		A[i] = -1;

	for (i = 0; i < N; i++) {
		scanf("%d %d", &cowN, &position);
		if (A[cowN] == -1)
			A[cowN] = position;
		else
			if (A[cowN] != position) {
				count++;
				A[cowN] = position;
			}
	}
	printf("%d", count);

	return 0;
}
