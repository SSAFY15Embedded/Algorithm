#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 마을의 이장은 마을을 두 개의 분리된 마을로 분할할 계획을 가지고 있다.
// 마을을 분할할 때는 각 분리된 마을 안에 집들이 서로 연결되도록 분할해야 한다. 
// 분리된 두 마을 사이에 있는 길들은 필요가 없으므로 없앨 수 있다.
// 유지비의 합을 최소

// 마을을 2개로 분리한다.
// root가 2개 존재 
// 일단 하나로 쭉 이은 다음에 아무거나 하나 없애면 됨

// 시간 초과 해결법
// for문 안에서 또 for문을 돌리니 시간이 터짐
// 근데 for문을 안돌리는 방법이 있어...?
// Union-find


struct Edge {
	int u, v, w;
};

int N, M; // N: 집의 개수, M: 길의 개수
int A, B, C;
int parent[100001];
vector<Edge> edges;
int cnt = 0;

int ans;

int Find(int n) {
	if (parent[n] == n)
		return n;
	else {
		return parent[n] = Find(parent[n]);
	}
}
void Union(int a, int b) {
	int rootA = Find(a);
	int rootB = Find(b);

	if (rootA == rootB)
		return;

	parent[rootB] = rootA;
}

bool cmp(Edge a, Edge b) {
	return a.w < b.w;
}

void kruskal() {
	// parent 초기화
	for (int i = 1; i <= N; i++)
		parent[i] = i;

	// edges sort
	sort(edges.begin(), edges.end(), cmp);

	for (int i = 0; i < edges.size(); i++) {
		int u = edges[i].u;
		int v = edges[i].v;
		int w = edges[i].w;

		if (parent[u] == parent[v])
			continue;

		Union(u, v);
		ans += w;
		cnt++;
		if (cnt == N - 2)
			return;
	}
}

int main() {
	cin >> N >> M;

	// 현재 집의 유지비
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;

		edges.push_back({ A, B, C });
	}

	kruskal();

	cout << ans;
}
