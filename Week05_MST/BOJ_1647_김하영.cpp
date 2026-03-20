#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// 최소 한 개의 집이 있도록 2개로 분할
// 각각의 최소 경로의 합

struct Edge {
	int A, B, cost;
	bool operator <(Edge right) const {
		if (cost < right.cost) return true;
		if (cost > right.cost) return false;
		return false;
	}
};

int N, M;
int parent[100000];
Edge edges[100000];
//vector<Edge>edges;
int arrA[100000];
int arrB[100000];

int Find(int now) {
	if (now == parent[now]) return now;
	return parent[now] = Find(parent[now]);
}

void Union(int A, int B) {
	int rootA = Find(A);
	int rootB = Find(B);
	if (rootA == rootB) return;
	parent[rootB] = rootA;
}

int mst() {
	// parent 초기화
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	// 길 연결
	int sum = 0;
	for (int i = 0; i < M; i++) {
		Edge now = edges[i];
		if (Find(now.A) == Find(now.B)) continue;
		Union(now.A, now.B);
		sum += now.cost;
	}
	return sum;
}

void dfs(int now, int level) {
	if (now == level) {

	}

	for (int i = 1; i <= N; i++) {
		if (visited[i] == 1) continue;
		visited[i] = 1;
		dfs(now + 1, level);
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		//edges.push_back({ A, B, C });
		edges[i] = { A, B, C };
	}
}
