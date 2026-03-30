#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

// 한 섬과 다른 섬을 잇는 다리 하나만을 만들기로 하였고, 
// 그 또한 다리를 가장 짧게 하여 돈을 아끼려 함
// 0은 바다, 1은 육지
// 1인 곳마다 floodfill 을 돌린다
// 각 육지마다 번호를 붙인다
// 번호가 붙어있는 곳에서 출발해서 다음 번호로 갈 때까지 0 부분을 채운다

struct Node {
	int y, x;
};

int N, cnt = 1;
int mat[100][100];
int visited[100][100];
int ydir[] = { -1, 1, 0, 0 };
int xdir[] = { 0, 0, -1, 1 };
int bridge[100][100];
int MIN = 21e8;

void bfs(int y, int x, int cnt) {
	// 1. 사전 설정
	queue<Node> q;

	// 2. 시작 노드 설정
	visited[y][x] = cnt;
	q.push({ y, x });

	// 큐가 빌 때까지
	while (!q.empty()) {
		// 3. 현재 노드 확인
		Node now = q.front();
		q.pop();

		// 4. next 확인
		for (int i = 0; i < 4; i++) {
			int ny = now.y + ydir[i];
			int nx = now.x + xdir[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= N)
				continue;

			if (visited[ny][nx] != 0)
				continue;

			if (mat[ny][nx] == 0)
				continue;

			// 5. next 등록
			visited[ny][nx] = cnt;
			q.push({ ny, nx });
		}
	}
}

void minBridge(int y, int x, int cnt) {
	// 1. 사전 설정
	queue<Node> q;
	memset(bridge, -1, sizeof(bridge));

	// 2. 시작 노드 설정
	bridge[y][x] = 0;
	q.push({y, x});

	// 큐가 빌 때까지
	while (!q.empty()) {
		// 3. 현재 노드
		Node now = q.front();
		q.pop();

		// 4. next 찾기
		for (int i = 0; i < 4; i++) {
			int ny = now.y + ydir[i];
			int nx = now.x + xdir[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= N)
				continue;

			if (visited[ny][nx] == cnt)
				continue;

			if (visited[ny][nx] != 0 && visited[ny][nx] != cnt) {
				MIN = min(MIN, bridge[now.y][now.x]);
				return;
			}

			if (mat[ny][nx] == 0 && bridge[ny][nx] == -1) {
				bridge[ny][nx] = bridge[now.y][now.x] + 1;
				q.push({ ny, nx });
			}
		}
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> mat[i][j];
	}

	// 섬 체크
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (mat[i][j] == 1 && visited[i][j] == 0) {
				bfs(i, j, cnt);
				cnt++;
			}
		}
	}

	// 다리 놓기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] != 0) {
				minBridge(i, j, visited[i][j]);
			}
		}
	}

	cout << MIN;

}
