#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
int parent[100001];

struct Node {
    int a;
    int b;
    int cost;
};

vector<Node> node;

int Find(int now) {
    if (parent[now] == now) return now;
    return Find(parent[now]);
}

void Union(int a, int b) {
    int RootA = Find(a);
    int RootB = Find(b);
    if (RootA == RootB) return;
    parent[RootB] = RootA;
}


int main() {

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        node[i].a = a;
        node[i].b = b;
        node[i].cost = cost;
    }
    sort(node.begin(), node.end());

    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }


    for (int i = 0; i < m; i++) {

        if (Find(node[i].a) != Find(node[i].b)) { 
            Union(node[i].a, node[i].b);
       
        }

    }


  

}
