#include <iostream>
#include <queue>
#include <vector>
using namespace std;


int map[101][101];
int r, c;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int one_cnt;
int visited[101][101];
vector<pair<int, int>> v;
void bfs(int y, int x) {
	
	queue<pair<int, int>> q;
	q.push({ y,x });
	
	
	
	auto now = q.front(); q.pop();
	for (int i = 0; i < 4; i++) {
		int ny = now.first + dy[i];
		int nx = now.second + dx[i];
		if (map[ny][nx] == 0) { // 4방향 중 하나라도 0이면
			v.push_back({ now.first, now.second });
			break;
		}

	}
	
}
int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
		}
	}

	bool flag = true;
	int hour = -1;
	int ans = 0;
	while (flag) {
		ans = one_cnt;
		one_cnt = 0;
	
		hour++;
		flag = false;
		v.clear();
		for (int i = 1; i < r - 1; i++) {
			for (int j = 1; j < c - 1; j++) {
				if (map[i][j] == 1) {
					one_cnt++; // 1의 총 개수

					bfs(i, j);
					flag = true;
				}

			}
		}
		
		for (int i = 0; i < v.size(); i++) {
			map[v[i].first][v[i].second] = 0;
		}
	
	}

	
	cout << hour << '\n';
	cout << ans;

	
	

}
