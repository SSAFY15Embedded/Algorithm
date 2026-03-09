#include <iostream>
#include <string>
using namespace std;

int SUM(string input) {
	int flag = 0;
	int index = 0;
	int sum = 0;
	while (1) {
		int a = input.find('+', index + 1);
		int b = input.find('-', index + 1);
		int next;
		if (a == -1 && b == -1) {
			sum += stoi(input.substr(index));
			break;
		}
		else if (a == -1) {
			next = b;
		}
		else if (b == -1) {
			next = a;
		}
		else if (a < b) {
			next = a;
		}
		else if (b < a) {
			next = b;
		}

		sum += stoi(input.substr(index, next - index));

		index = next + 1;
	}

	return sum;
}

int main() {
	string input, input1, input2;
	cin >> input;

	int find = input.find('-');
	int ans = 0;

	if (find == -1) {
		ans += SUM(input);
	}
	else {
		input1 = input.substr(0, find);
		input2 = input.substr(find + 1);
		ans += SUM(input1);
		ans -= SUM(input2);
	}

	cout << ans;
}
