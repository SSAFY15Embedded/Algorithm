#include <iostream>
#include <string>
using namespace std;

int N;
string str[100];
int cnt = 0; // 그룹 단어의 수
int flag;

void func(int now, string str) {
	// 1. 기저 조건
	if (now == str.length()) {
		return;
	}
	// 2. 재귀 조건
	char a = str[now]; // 현재 알파벳
	int b = str.find(a, now + 1); // 다음으로 나타나는 index
	if (b != now + 1 && b != -1) flag = 0; // 바로 다음에 나타나지 않으면
	func(now + 1, str);
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str[i];
	}

	for (int i = 0; i < N; i++) {
		flag = 1;
		func(0, str[i]);
		if (flag == 1) cnt++;
	}
	cout << cnt;
}
