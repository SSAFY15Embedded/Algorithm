#include <iostream>
using namespace std;

int N, M;
int visited[8] = { 0 };
int path[8] = { 0 };

void dfs(int now) {
	// 1. 기저 조건
	if (now == N) {
		for (int i = 0; i < M; i++) {
			cout << path[i] << " ";
		}
		cout << endl;
	}
	// 2. 재귀 조건
	for (int i = 1; i <= N; i++) {
		if (visited[i] == 1) continue;
		visited[i] = 1;
		path[now] = i;
		dfs(now + 1);
		visited[i] = 0;
		path[now] = 0;
	}
}

int main() {
	cin >> N >> M;
	dfs(0);
}
