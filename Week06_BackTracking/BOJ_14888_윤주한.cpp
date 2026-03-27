#include <iostream>
using namespace std;

int N;
int arr[11];
int oper[4]; //0:+, 1:-, 2:*, 3:/,
int sum = 0;
int MAX = 0x80000000;
int MIN = 0x7FFFFFFF;

void DFS(int level){
    if(level == N - 1){
        if(sum > MAX){
            MAX = sum;
        }
        if(sum < MIN){
            MIN = sum;
        }
    }
    else{
        for(int i = 0; i < 4; i++){
            if(oper[i] == 0){ //해당 연산자의 개수가 0이면 continue
                continue;
            }

            int tmp = sum;
            if(i == 0){
                sum += arr[level + 1];
            }
            else if(i == 1){
                sum -= arr[level + 1];
            }
            else if(i == 2){
                sum *= arr[level + 1];
            }
            else if(i == 3){
                sum /= arr[level + 1];
            }
            oper[i] -= 1; //연산자를 사용할 때 마다, 해당 연산자의 개수를 하나씩 뺀다.
            DFS(level + 1);
            sum = tmp;
            oper[i] += 1;
        }
    }
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    
    for(int i = 0; i < 4; i++){
        cin >> oper[i];    
    }

    sum += arr[0];
    DFS(0);

    cout << MAX << '\n';
    cout << MIN << '\n';
}
