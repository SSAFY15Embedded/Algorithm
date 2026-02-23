#include <iostream>
#define MAX 500000
using namespace std;

int input;
int arr[MAX];
int front = 0; //카드 덱의 맨 위
int rear; //카드 덱의 맨 아래
int ans;

int main() {
    //1. 초기화
    cin >> input;
    for(int i = 0; i < input; i++){
        arr[i] = i + 1;
    }
    rear = input - 1;

    //2. 실행
    int cnt = 1;
    while(1){
        //2-1. 확인: 카드가 한장이면(front와 rear가 같으면) 정답
        if(front == rear){
            ans = arr[front];
            break;
        }

        //2-1. 홀수 번째는 맨위 카드를 버린다(front를 한칸 옮김으로서 수행)
        if(cnt % 2 == 1){
            front += 1;
        }
        //2-2. 짝수 번째는 맨위 카드를 아래로 옮긴다(rear의 한칸 뒤에 front에 해당하는 카드를 복사하고 front를 한칸 옮김)
        else if(cnt % 2 == 0){
            rear += 1;
            if(rear == MAX){
                rear = 0;
            }
            arr[rear] = arr[front];
            front += 1;
        }

        //**front나 rear나 하나씩 더할 때 마다 MAX인지 확인하여 배열의 맨 앞으로 위치를 바꾸는 작업이 필요
        if(front == MAX){
            front = 0;
        }
        
        cnt +=1;
    }

    cout << ans;
    return 0;
}
