#include <iostream>
#include <string>

using namespace std;

int main() {

	int N;
	string str;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		str += to_string(i);
	}

	int cnt = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '3' || str[i] == '6' || str[i] == '9') {
			cnt++;
		}
	}
	cout << cnt;

}
