#include <iostream>
#define MAX 500000
using namespace std;

int input;
int arr[MAX];
int front = 0;
int rear;
int ans;

int main() {
    cin >> input;
    for(int i = 0; i < input; i++){
        arr[i] = i + 1;
    }
    rear = input - 1;

    int cnt = 1;
    while(1){
        if(front == rear){
            ans = arr[front];
            break;
        }
        
        if(cnt % 2 == 1){
            front += 1;
        }
        else if(cnt % 2 == 0){
            rear += 1;
            if(rear == MAX){
                rear = 0;
            }
            arr[rear] = arr[front];
            front += 1;
        }

        if(front == MAX){
            front = 0;
        }
        
        cnt +=1;
    }

    cout << ans;
    return 0;
}
