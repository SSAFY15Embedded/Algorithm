#include <iostream>

using namespace std;
int n, m;

int dat[9];
void dfs(int cnt) {

    if (cnt == m) {
        for (int i = 0; i < m; i++) {
            cout << dat[i] << ' ';
        }
        cout << '\n';
        
        return;
    }
   
    for (int i = 1; i <= n; i++) {
        if(cnt>0 && dat[cnt-1] > i) continue;
        dat[cnt] = i;
        dfs(cnt+1);
        

    }
}

int main() {
    
    cin >> n >> m;
    dfs(0);
}
