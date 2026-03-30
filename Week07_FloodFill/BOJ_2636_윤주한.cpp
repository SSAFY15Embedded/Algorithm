#include <iostream>
#include <queue>
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

struct YX{
    int y, x;
};

int N, M;
int map[100][100];
int visited[100][100];
int remain[10000]; //i번째 시간마다 남아있는 치즈의 개수
int cnt = 0; //남은 치즈 개수
int ans = 0; //i번째 시간

void BFS(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            visited[i][j] = 0;
        }
    }
    
    queue<YX> q;
    q.push({0, 0});
    visited[0][0] = 1;

    while(!q.empty()){
        YX now = q.front();
        q.pop();

        //치즈에 도달하면 치즈를 녹이고 더 이상 진입하지 않는다.
        if(map[now.y][now.x] == 1){
            map[now.y][now.x] = 0;
            cnt -= 1;
            continue;
        }

        for(int i = 0; i < 4; i++){
            int Y = now.y + dy[i];
            int X = now.x + dx[i];

            if(Y < 0 || Y >= N || X < 0 || X >= M){
                continue;
            }

            if(visited[Y][X] == 1){
                continue;
            }

            visited[Y][X] = 1;
            q.push({Y, X});
        }
    }
}

int main() {
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
            cnt += map[i][j];
        }
    }

    while(cnt > 0){
        remain[ans] = cnt;
        BFS();
        ans += 1;
    }

    cout << ans << '\n';
    cout << remain[ans - 1];
}
