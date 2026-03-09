#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[10];
int path[10];

void dfs(int now) {
	if (now == M) {
		for (int i = 0; i < M; i++) {
			cout << path[i] << " ";
		}
		cout << endl;

		return;
	}

	if (now == 0) {
		for (int i = 1; i <= N; i++) {
			path[now] = i;
			dfs(now + 1);
		}
	} 
	else {
		for (int i = path[now - 1]; i <= N; i++) {
			path[now] = i;
			dfs(now + 1);
		}
	}
}

int main() {
	cin >> N >> M;

	dfs(0);
}
