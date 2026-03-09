#include <iostream>

#include <cmath>
#include <string>
using namespace std;


int cnt;
int main() {
	int n;
	cin >> n;
	string sn = to_string(n);
	for (int i = 1; i <= n; i++) {
		string sn = to_string(i);
		for (int j = 0; j < sn.length(); j++) {
			if (sn[j] == '3' || sn[j] == '6' || sn[j] == '9') cnt++;
		}
	}
	cout << cnt;
}
