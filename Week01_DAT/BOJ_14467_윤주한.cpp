#include<iostream>
using namespace std;

int N;
int DAT[11];
int cnt = 0;

int main(){
    cin >> N;
    for(int i = 0; i < 11; i++){
        DAT[i] = -1;
    }

    for(int i = 0; i < N; i++){
        int a, b;
        cin >> a >>b;
        
        if(DAT[a] == -1){
            DAT[a] = b;
        }
        else if(DAT[a] != b){
            cnt++;
            DAT[a] = b;
        }
    }
    
    cout << cnt;
}
