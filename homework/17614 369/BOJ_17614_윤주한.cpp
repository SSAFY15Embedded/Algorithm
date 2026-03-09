#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	cin >> N;

	int sum = 0;
	for (int i = 1; i <= N; i++) {
		string str = to_string(i);

		for (int j = str.find('3'); j != -1; j = str.find('3', j + 1)) {
			sum += 1;
		}

		for (int j = str.find('6'); j != -1; j = str.find('6', j + 1)) {
			sum += 1;
		}

		for (int j = str.find('9'); j != -1; j = str.find('9', j + 1)) {
			sum += 1;
		}
	}

	cout << sum;
}
