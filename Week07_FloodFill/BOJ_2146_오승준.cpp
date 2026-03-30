#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int map[101][101];
int r, c;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int cheese_cnt = 0;
bool visited[101][101];

void bfs() {
    queue<pair<int, int>> q;
    q.push({ 0, 0 });
    visited[0][0] = true;

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny >= 0 && nx >= 0 && ny < r && nx < c && !visited[ny][nx]) {
                visited[ny][nx] = true; 
                
                if (map[ny][nx] == 0) {
                    q.push({ ny, nx });
                }
                else if (map[ny][nx] == 1) {
                    map[ny][nx] = 0;
                    cheese_cnt--; 
                    
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> map[i][j];
            if (map[i][j] == 1) cheese_cnt++;
        }
    }

    int hour = 0;
    int ans = 0;

    while (cheese_cnt > 0) {
        ans = cheese_cnt; 
        memset(visited, false, sizeof(visited)); 
        bfs(); 
        
        hour++;
    }

    cout << hour << '\n';
    cout << ans << '\n';

    return 0;
}
