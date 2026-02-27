/* [1522] 문자열 교환

* 문제 설명:
- a와 b로만 이루어진 문자열이 주어질 때 a를 모두 연속으로 만들고자 함
- 문자열은 원형이므로, 처음과 끝은 서로 인접해있음
- 예시:
  - "ccazb" → 그룹 단어
  - "kin" → 그룹 단어
  - "ccaza" → 그룹 아님 (a가 중복 등장)
  - "kink" → 그룹 아님 (k가 떨어져 있음)

* 풀이 요약:
1. 단어를 문자 배열로 입력받음
2. 문자 변경이 감지될 때마다 이전 문자를 추적용 배열에 저장
3. 이후 같은 문자가 나오면 그룹 단어가 아님
4. 조건에 맞으면 count++
5. 마지막에 count 출력
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
