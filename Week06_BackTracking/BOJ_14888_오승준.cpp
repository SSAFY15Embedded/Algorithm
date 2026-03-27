#include <iostream>

using namespace std;


int arr[12];
char oper[5] = { '+','-','*','/' };
int operNum[5];
int n;

char path[11];

int mx;
int mn=21e8;
int res;
void backtrack(int now) {
	if (now == n - 1) {
		res = arr[0];
		for (int i = 0; i < n; i++) {

			if (path[i] == '+') {
				res += arr[i + 1];
			}
			else if (path[i] == '-') {
				res -= arr[i + 1];
			}
			else if (path[i] == '*') {
				res *= arr[i + 1];
			}
			else {
				res /= arr[i + 1];
			}

		}

		if (mx < res) {
			mx = res;
		}
		if (mn > res) {
			mn = res;
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (operNum[i] > 0) {
			path[now] = oper[i];
			backtrack(now+1);
			path[now] = '\0';
		}
	}
}
int main() {
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> operNum[i];
	}
	backtrack(0);

	cout << mx << '\n';
	cout << mn << '\n';
}
