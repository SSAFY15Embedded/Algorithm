#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	// n % 5 = row
	// 저걸 몇번 하느냐
	int n1, n2;
	int r1, c1 = 0, r2, c2 = 0, result;

	scanf("%d %d", &n1, &n2);
	
	r1 = (n1 - 1) % 4;
	c1 = (n1 - 1) / 4;

	r2 = (n2 - 1) % 4;
	c2 = (n2 - 1) / 4;

	if (r2 > r1)
		if (c2 > c1)
			result = r2 - r1 + c2 - c1;
		else
			result = r2 - r1 + c1 - c2;
	else
		if (c2 > c1)
			result = r1 - r2 + c2 - c1;
		else
			result = r1 - r2 + c1 - c2;
	
	printf("%d", result);

}
