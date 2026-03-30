#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

// 가장자리에는 치즈가 없고, 치즈에는 하나 이상의 구멍이 있다.
// 치즈는 공기 중에 놓으면 녹게 됨, 한시간 지나면 녹아 없어짐
// 치즈 구멍 속에는 공기가 없지만, 구멍을 둘러싼 치즈가 녹아서 구멍이 열리면 공기가 들어간다
// 치즈가 모두 녹아서 없어지는 데 걸리는 시간

// 일단 floodfill 돌려서 치즈의 모양을 알아낸다.
// 치즈가 공기와 맞닿아있으면 없어짐
// 공기랑 닿아있는지를 판단하는 법
// 플러드필 돌리다가 가장자리를 만나면 이건 바깥쪽에 있는 것이다 -> 다음 번에 없어질 것 체크만 -> mat 조정

struct Node {
	int y, x;
};

int N, M; // 세로와 가로
int mat[100][100];
int visited[100][100];
int ydir[] = { -1, 1, 0, 0 };
int xdir[] = { 0, 0, -1, 1 };
vector<Node> path;
int ans, cnt;

void bfs(int y, int x) {
	// 1. 사전 설정
	memset(visited, -1, sizeof(visited));
	queue<Node> q;

	// 2. 시작 노드 설정
	q.push({ y, x });
	visited[y][x] = 1;

	// 큐가 빌 때까지
	while (!q.empty()) {
		// 3. 현재 노드 확인
		Node now = q.front();
		q.pop();

		if(now.y == 0 || now.y == N - 1)
			if (now.x == 0 || now.x == N - 1) {
				path.push_back({ y, x });
				return;
			}

		// 4. next 찾기
		for (int i = 0; i < 4; i++) {
			int ny = now.y + ydir[i];
			int nx = now.x + xdir[i];
			
			if (ny < 0 || nx < 0 || ny >= N || nx >= M)
				continue;

			if (mat[ny][nx] == 1 || visited[ny][nx] != -1)
				continue;

			// 5. next 등록
			visited[ny][nx] = 1;
			q.push({ ny, nx });
		}
	
	}

}

// 전부 없어졌는지
int isCheck() {
	int temp = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (mat[i][j] == 1)
				temp++;
		}
	}
	return temp;
}

// 모두 녹기 한 시간 전에 남아있는 치즈조각이 놓여 있는 칸의 개수를 출력한다. 
int main() {
	int temp = 1;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> mat[i][j];
		}
	}

	while (temp != 0) {
		// 가장자리 치즈 찾기
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (mat[i][j] == 1)
					bfs(i, j);
			}
		}
		temp = isCheck();

		for (int i = 0; i < path.size(); i++)
			mat[path[i].y][path[i].x] = 0;

		cnt++;

		if (temp == 0)
			break;

		ans = temp;
	}

	cout << cnt - 1 << endl;
	cout << ans;

}
