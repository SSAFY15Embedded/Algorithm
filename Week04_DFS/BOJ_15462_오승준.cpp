#include <iostream>

using namespace std;
int n, m;

int dat[9];
void dfs(int cnt) {

    if (cnt == m) {
        for (int i = 1; i <= m; i++) {
            cout << dat[i] << ' ';
        }
        cout << '\n';
        
        return;
    }
   
    for (int i = 1; i <= n; i++) {
        dat[i] = i;
        dfs(cnt+1);
        

    }
}

int main() {
    
    cin >> n >> m;
    dfs(0);
}
