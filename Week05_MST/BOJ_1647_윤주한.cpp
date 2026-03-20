#include <iostream>
#include <queue>
using namespace std;

struct Edge{
int from, to, cost;
bool operator<(const Edge right)const{
    return cost > right.cost;
}
};

int N, M;
int parent[100001];
priority_queue<Edge> pq;
int ans = 0;
int cnt = 0;

int Find(int A){
    if (parent[A] == A) {
        return A;
    }
    return parent[A] = Find(parent[A]);
}

void Union(Edge now){
    int rootA = Find(now.from);
    int rootB = Find(now.to);
    if(rootA == rootB){
        return;
    }

    ans += now.cost;
    cnt++;
    parent[rootB] = rootA;
}

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < M; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        pq.push({from, to, cost});
    }

    while (!pq.empty() && cnt != N - 2) {
        Edge now = pq.top();
        pq.pop();
        Union(now);
    }

    cout << ans;
    return 0;
}
