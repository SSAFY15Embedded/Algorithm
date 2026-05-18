#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
int map[101][101];

int n;

struct Node {
	int y;
	int x;
	int cost;
};

int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };

int visited[101][101];

int bfs(Node start, Node end) {
	queue<Node> q;

	memset(visited, 0, sizeof(visited));
	visited[start.y][start.x] = 1;
	q.push({ start.y, start.x, 0 });
	while (!q.empty()) {
		Node now = q.front(); q.pop();
		if (now.y == end.y && now.x == end.x) {
			return now.cost;
		}
		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || ny >= n) continue;
			if (visited[ny][nx]) continue;
			if(map[ny][nx]<)
			visited[ny][nx] = 1;
			int nextcost = map[ny][nx];
			q.push({ ny, nx , nextcost+now.cost});
		}
	}
}

int main() {
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}

		Node start = { 0,0 };
		Node end = { n - 1, n - 1 };

		int ans = bfs(start, end);
		cout << '#' << tc << ' ' << ans;
	}
}
