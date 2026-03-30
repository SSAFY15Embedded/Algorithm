#include <iostream>
#include <queue>
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

struct YX{
    int y, x;
};

int N;
int map[100][100];
int island[100][100];
int i_cnt = 0;
int visited[100][100];
int ans = 0x7FFFFFFF;

int BFS(int startY, int startX, int num){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            visited[i][j] = -1;
        }
    }
    
    queue<YX> q1, q2;
    q1.push({startY, startX});
    q2.push({startY, startX});
    island[startY][startX] = num;
    visited[startY][startX] = 0;

    while(!q1.empty()){
        YX now = q1.front();
        q1.pop();

        for(int i = 0; i < 4; i++){
            int Y = now.y + dy[i];
            int X = now.x + dx[i];

            if(Y < 0 || Y >= N || X < 0 || X >= N){
                continue;
            }
            
            if(visited[Y][X] != -1){
                continue;
            }

            if(map[Y][X] == 0){
                continue;
            }

            visited[Y][X] = 0;
            island[Y][X] = num;
            q1.push({Y, X});
            q2.push({Y, X});
        }
    }

    while(!q2.empty()){
        YX now = q2.front();
        q2.pop();

        for(int i = 0; i < 4; i++){
            int Y = now.y + dy[i];
            int X = now.x + dx[i];

            if(Y < 0 || Y >= N || X < 0 || X >= N){
                continue;
            }
            
            if(visited[Y][X] != -1){
                continue;
            }

            if(map[Y][X] == 1 && island[Y][X] != num){
                return visited[now.y][now.x];
            }

            visited[Y][X] = visited[now.y][now.x] + 1;
            q2.push({Y, X});
        }
    }
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(map[i][j] == 1 && island[i][j] == 0){
                int length = BFS(i, j, ++i_cnt);
                if(length < ans){
                    ans = length;
                }
            }
        }
    }

    cout << ans;
}
