#include <iostream>
#include <string>
using namespace std;

string A, B;

int func(string num) {
    string newNum = "";
    for (int i = 2; i >= 0; i--) {
        newNum += num[i];
    }
    return stoi(newNum);
}

void comp(int A, int B) {
    if (A > B) cout << A;
    else cout << B;
}

int main() {
	cin >> A >> B;
    comp(func(A), func(B));
}
