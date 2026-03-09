#include <iostream>
#include <string>

using namespace std;

int main() {

	string str1, str2;
	cin >> str1 >> str2;

	int flag = 0;
	for (int i = 2; i >= 0; i--) {
		if (str1[i] > str2[i]) {
			flag = 1;
			break;
		}
		if (str1[i] < str2[i]) {
			flag = 2;
			break;
		}
	}
	if (flag == 1) {
		for (int i = 2; i >= 0; i--) {
			cout << str1[i];
		}
	}

	if (flag == 2) {
		for (int i = 2; i >= 0; i--) {
			cout << str2[i];
		}
	}
}
