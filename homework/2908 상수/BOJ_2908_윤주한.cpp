#include <iostream>
#include <string>
using namespace std;

int main() {
	string A, B;
	cin >> A >> B;

	string rA, rB;
	for (int i = A.length() - 1; i >= 0; i--) {
		rA.push_back(A[i]);
	}
	for (int i = B.length() - 1; i >= 0; i--) {
		rB.push_back(B[i]);
	}


	cout << ((rA > rB) ? rA : rB);
}
