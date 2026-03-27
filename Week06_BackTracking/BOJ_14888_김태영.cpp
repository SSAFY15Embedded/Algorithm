#include <iostream>

using namespace std;

int Min, Max;
int N;
int A[12];
int oper[4];
int use[4];

void dfs(int now, int result){
    if (now >= N){
        if (result > Max)
            Max = result;
        if (result < Min)
            Min = result;
       
        return;
    }
    
    for (int i = 0; i < 4; i++){
        if (use[i] == oper[i]) continue;
        
        use[i]++;
        int value;
        if ( i == 0)
            value = result + A[now];
        if ( i == 1)
            value = result - A[now];
        if ( i == 2)
            value = result * A[now];
        if ( i == 3)
            value = result / A[now];
        
        dfs(now+1, value);
        
        use[i]--;
    }
}

int main(){
    Min = 21e8;
    Max = -21e8;
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> A[i];
    }
    for (int i = 0; i < 4; i++){
        cin >> oper[i];
    }
    
    dfs(1, A[0]);
    
    cout << Max << endl << Min;
}
