#include <iostream>

using namespace std;

int N;
int DAT[26];
int ans = 0;

int isOK(char str[101]){
    //DAT 초기화
    for(int i = 0; i < 26; i++){
        DAT[i] = 0;
    }
    
    char prev = '\0';
    for(int i = 0; str[i] != '\0'; i++){
        if(prev == str[i]){
            continue;
        }
        else{//이전 문자와 현재 문자가 다를 경우
            if(DAT[str[i] - 'a'] > 0){//현재 문자가 사용된 적이 있는 확인
                return 0;
            }
            else{//현재 문자가 사용된 적이 없으면 표기
                DAT[str[i] - 'a']++;    
            }
        }
        prev = str[i];
    }
    return 1;
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++){
        char str[101];
        cin >> str;
        if(isOK(str) == 1){
            ans++;
        }
    }
    cout << ans;
}
