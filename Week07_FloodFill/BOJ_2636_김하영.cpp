#include <iostream>
#include <queue>
using namespace std;

// 현재 노드가 0일 때, 다음 노드(상하좌우)가 1이면 녹음

int N, M;
int MAP[101][101];
int visited[101][101];
struct Node {
	int y, x;
};
int ydir[] = { -1,1,0,0 };
int xdir[] = { 0,0,-1,1 };
int cnt = 0;
int idx = 0;
int sizeArr[101];

void func() {
	// 1. 사전 준비
	queue<Node>q;
	// 2. 시작 노드 큐에 등록
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (MAP[i][j] == 0) {
				q.push({ i, j });
				visited[i][j] = 1;
			}
		}
	}
	// 큐가 비기 전까지
	while (!q.empty()) {
		for (int i = 0; i < q.size(); i++) {
			// 3. 맨 앞 노드 추출
			Node now = q.front(); q.pop();
			// 4. next 찾기
			for (int i = 0; i < 4; i++) {
				int ny = now.y + ydir[i];
				int nx = now.x + xdir[i];
				if (ny >= N || nx >= M || ny < 0 || nx < 0) continue;
				if (visited[ny][nx] == 1) continue;
				if (MAP[ny][nx] == 0) continue;
				visited[ny][nx] = 1;
				MAP[ny][nx] = 0;
				q.push({ ny,nx });
			}
		}
		
		// 남은 치즈칸 개수 구하기
		int size = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (MAP[i][j] == 1) size++;
			}
		}
		if (size == 0) break;
		sizeArr[cnt++] = size;
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
		}
	}

	func();
	cout << cnt << endl;
	cout << sizeArr[cnt - 1];
}
