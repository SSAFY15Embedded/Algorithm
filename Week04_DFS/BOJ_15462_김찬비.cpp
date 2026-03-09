#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> path;

// 길이가 K인 수열 A가 A1 ≤ A2 ≤ ... ≤ AK-1 ≤ AK를 만족하면, 비내림차순

void dfs(int level) {
	// 1. 기저 조건
	if (level == M) {
		for (int i = 0; i < path.size(); i++)
			cout << path[i] << " ";
		cout << endl;
		return;
	}
	// 2. 재귀 조건
	for (int i = 1; i <= N; i++) {
		int next = i;

		if (!path.empty() && next < path.back())
			continue;

		path.push_back(next);
		dfs(level + 1);
		path.pop_back();
	
	}
}

int main() {
	cin >> N >> M;

	dfs(0);

	return 0;
}
