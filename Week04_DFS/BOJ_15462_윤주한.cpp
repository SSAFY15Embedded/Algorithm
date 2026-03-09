#include <iostream>
using namespace std;

int N;
int M;
int path[8];

void DFS(int level){
    if(level == M){
        for(int i = 0; i < level; i++){
            cout << path[i] << ' ';
        }
        cout << '\n';
    }
    else{
        for(int i = 1; i <= N; i++){
            if(level > 0 && i < path[level - 1]){
                continue;
            }

            path[level] = i;
            DFS(level + 1);
        }
    }
}

int main() {
    cin >> N >> M;
    DFS(0);
    
    return 0;
}
