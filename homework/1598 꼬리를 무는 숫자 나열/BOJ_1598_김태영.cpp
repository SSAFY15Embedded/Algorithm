#include <iostream>
#include <cmath>

using namespace std;

int A, B;

int main() {
	cin >> A >> B;

	int y = abs(((A - 1) % 4) - ((B - 1) % 4));
	int x = abs(((A - 1) / 4) - ((B - 1) / 4));

	cout << x + y;
}
