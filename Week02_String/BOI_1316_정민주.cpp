#include<iostream>
#include<vector>
#include<string>
using namespace std;

int N;
string name;
int cnt = 0;
int used[26];

void func(int level) {
	if (level == N-1) {
		cout << cnt;
		return;
	}


	for (int i = 0; i < name.length(); i++) {
		if (name[i - 1] != name[i] && used[name[i]] == 1) continue;
		else cnt++;
		func(level + 1);

		cnt = 0;
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> name;
	}

	func(0);
}



//int main() {
//	int N;
//	cin >> N;
//
//	string name;
//	cin >> name;
//
//	int used[26] = { 0 };
//	int cnt = 0;
//
//	for (int j = 0; j < N; j++) {
//		for (int i = 0; i < name.length(); i++) {
//			if (i == 0) cnt++;
//			else if (name[i - 1] != name[i] && used[name[i]] == 1) continue;
//		}
//		cnt++;
//	}
//
//	
//	cout << cnt;
//
//	
//}
