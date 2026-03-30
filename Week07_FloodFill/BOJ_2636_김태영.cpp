#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int H, W;
int map[100][100];
int visited[100][100];
struct Node {
	int y, x;
};

void bfs(int y, int x, int div) {

	int ydir[] = {1, -1, 0, 0};
	int xdir[] = {0, 0, -1, 1};

	queue<Node>q;
	visited[y][x] = div;
	q.push({y, x});

	while (!q.empty()) {
		Node now = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + ydir[i];
			int nx = now.x + xdir[i];

			if (ny < 0 || nx < 0 || ny >= H || nx >= W) continue;
			if (visited[ny][nx] != 0) continue;
			if (div < 5) {
				if (map[ny][nx] == 1) continue;
			}
			else {
				if (map[ny][nx] == 0) continue;
			}

			visited[ny][nx] = div;
			q.push({ny, nx});
		}
	}
}

void check(int y, int x) {

	int ydir[] = { 1, -1, 0, 0 };
	int xdir[] = { 0, 0, -1, 1 };

	for (int i = 0; i < 4; i++) {
		int ny = y + ydir[i];
		int nx = x + xdir[i];

		if (visited[ny][nx] == 1) {
			visited[y][x] = 10;
			return;
		}
	}
}

int main() {

	cin >> H >> W;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> map[i][j];
		}
	}
	int cnt;
	int time = 0;
	int cheese = 0;
	while (1) {
		memset(visited, 0, sizeof(visited));
		
		cnt = 0;

		bfs(0, 0, 1); // 밖

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (map[i][j] == 0 && visited[i][j] == 0) {
					bfs(i, j, 3); // 구멍
				}
				if (map[i][j] == 1 && visited[i][j] == 0) {
					bfs(i, j, 9); // 치즈
				}
				if (map[i][j] == 1) cnt++;
			}
		}

		if (cnt == 0) break;

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (map[i][j] == 1) {
					check(i, j);
				}
			}
		}

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (visited[i][j] == 10) {
					map[i][j] = 0;
				}
			}
		}
		time++;
		cheese = cnt;
	}

	cout << time << " " << cheese;
}
