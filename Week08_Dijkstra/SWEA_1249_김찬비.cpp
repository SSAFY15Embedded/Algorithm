#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
 
using namespace std;
 
/*
공병대는 출발지(S) 에서 도착지(G)까지 가기 위한 도로 복구 작업을 빠른 시간 내에 수행하려고 한다.
 
도로가 파여진 깊이에 비례해서 복구 시간은 증가한다.
 
출발지에서 도착지까지 가는 경로 중에 복구 시간이 가장 짧은 경로에 대한 총 복구 시간은?
 
출발지에서 도착지까지 거리에 대해서는 고려할 필요가 없다.
*/
 
struct Edge {
    int y, x, cost;
    bool operator<(Edge right) const {
        return cost > right.cost;
    }
};
 
int T, N;
int mat[100][100];
int dist[100][100];
int ydir[] = { -1, 1, 0, 0 };
int xdir[] = { 0, 0, -1, 1 };
 
void init() {
    memset(mat, -1, sizeof(mat));
    memset(dist, -1, sizeof(dist));
    N = 0;
}
 
void input() {
    cin >> N;
    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int j = 0; j < N; j++) {
            mat[i][j] = s[j] - '0';
        }
    }
}
 
void dijkstra(Edge s, Edge e) {
    // 1. 사전 설정
    priority_queue<Edge> pq;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            dist[i][j] = 21e8;
 
    // 2. 시작 노드
    dist[s.y][s.x] = 0;
    pq.push({ s });
 
    // 큐가 빌 때까지
    while (!pq.empty()) {
        // 3. 최상위 노드
        Edge now = pq.top();
        pq.pop();
 
        if (now.y == e.y && now.x == e.x)
            return;
             
        if (now.cost > dist[now.y][now.x])
            continue;
 
        // 4. next 찾기
        for (int i = 0; i < 4; i++) {
            int ny = now.y + ydir[i];
            int nx = now.x + xdir[i];
 
            if (ny < 0 || nx < 0 || ny >= N || nx >= N) {
                continue;
            }
 
            int nextCost = now.cost + mat[ny][nx];
            if (nextCost >= dist[ny][nx])
                continue;
 
            // 5. next 등록
            dist[ny][nx] = nextCost;
            pq.push({ ny, nx, nextCost });
        }
    }
}
 
int main() {
    cin >> T;
 
    for (int test_case = 1; test_case <= T; test_case++) {
        init();
        input();
        dijkstra({ 0, 0, 0 }, { N - 1, N - 1, 0 });
 
        cout << "#" << test_case << " " << dist[N - 1][N - 1] << endl;
    }
     
    return 0;
}
