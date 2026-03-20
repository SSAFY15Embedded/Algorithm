#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ans;
int N, M;
struct Node {
	int from, to, cost;
	bool operator<(Node right) const {
		if (cost < right.cost) return true;
		if (cost > right.cost) return false;

		if (to < right.from) return true;
		if (to > right.from) return false;

		return false;
	}
};

Node road[1000001];
int parent[100001];
int side[100001];

int Find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int A, int B) {
	int rootA = Find(A);
	int rootB = Find(B);
	if (rootA == rootB) return;
	parent[B] = rootA; 
}

void Devide(int now, int cnt) {
	if (now > N) {
		if (cnt == 0 || cnt == N)
			return;

		for (int i = 1; i <= N; i++) {
			parent[i] = i;
		}

		int sum = 0;
		for (int i = 0; i < M; i++) {
			if (side[road[i].from] == side[road[i].to]) {
				if (parent[road[i].from] != parent[road[i].to]) {
					Union(road[i].from, road[i].to);
					sum += road[i].cost;
				}
			}
		}

		if (sum < ans) {
			ans = sum;
		}

		return;
	}

	side[now] = 0;
	Devide(now + 1, cnt);

	side[now] = 1;
	Devide(now + 1, cnt + 1);
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a > b) {
			int temp = a;
			a = b;
			b = temp;
		}
		road[i] = {a, b, c};
	}

	sort(road, road + M);
	ans = 21e8;
	Devide(1, 0);

	cout << ans;

}
