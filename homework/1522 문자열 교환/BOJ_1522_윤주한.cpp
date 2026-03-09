#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;
	int N = str.length();

	string result;
	for (int i = 0; i < N; i++) {
		if (str[i] == 'a') {
			result.insert(0, "a");
		}
		else if(str[i] == 'b') {
			result.push_back('b');
		}
	}

	int ans = 0x7FFFFFFF;
	for (int i = 0; i < N; i++) {
		int sum = 0;
		for (int j = i; j != (i - 1 + N) % N; j = (j + 1) % N) {
			if (str[j] == 'b' && result[(j - i + N) % N] != 'b') {
				sum += 1;
			}
		}

		if (sum < ans) {
			ans = sum;
		}
	}

	cout << ans;
}
