#include <iostream>
#include <string>

using namespace std;

int main() {

	string str;
	cin >> str;
	str += '+';

	int start = 0;
	int sum = 0;
	int flag = 0;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '-' || str[i] == '+') {
			if (flag == 1) {
				sum -= stoi(str.substr(start, i - start));
				start = i + 1;
			}
			if (flag == 0) {
				sum += stoi(str.substr(start, i - start));
				start = i + 1;
			}
		}

		if (str[i] == '-')
			flag = 1;
	}

	cout << sum;

}
