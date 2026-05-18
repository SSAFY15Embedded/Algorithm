#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int ans;
int map[101][101];
int N;
int dist[101][101];
char ch_map[101][101];
struct Node {
	int y, x;
};

int ydir[] = {0, 0, -1, 1};
int xdir[] = {-1, 1, 0, 0};

void init() {
	
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> ch_map[i][j];
			map[i][j] = ch_map[i][j] - '0';
		}
	}
}

void bfs(int y, int x) {
	queue<Node>q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dist[i][j] = 21e8;
		}
	}

	dist[y][x] = 0;
	q.push({y, x});

	while (!q.empty()) {
		Node now = q.front(); q.pop();
		
		for (int i = 0; i < 4; i++) {
			int ny = now.y + ydir[i];
			int nx = now.x + xdir[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
			if (dist[ny][nx] <= dist[now.y][now.x] + map[ny][nx]) continue;
			dist[ny][nx] = dist[now.y][now.x] + map[ny][nx];
			q.push({ny, nx});
		}
	}
}

void solution() {
	bfs(0, 0);
	ans = dist[N - 1][N - 1];
}

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		init();
		input();
		solution();

		cout << "#" << tc << " " << ans << endl;
	}
}
