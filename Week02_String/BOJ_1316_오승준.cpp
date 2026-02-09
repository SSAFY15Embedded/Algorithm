#include <iostream>
#include <string>
using namespace std;
bool ok = false;
bool visited[200];
int main() {
    int n;
    cin >> n;
    string s;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < s.length(); j++) {
            char temp = s[j];
            if (visited[temp - 0]) { // 현재의 단어에 재방문했다면 
                ok = true; // cnt를 세지 않도록.
                break; // 나가기
            } // 그룹단어 존재 시 나가기.
            visited[temp - 0] = 1; // 방문한 글자 방문표시
            for (int k = j + 1; k < s.length(); k++) { // 다음 글자 접근

                if (temp != s[k]) { //그전값과 다르다면 나가기.
                    j = k; // 다음 글자로 이동해서 탐색.
                    break;

                }
                j = k;// 다음 글자로 이동해서 탐색.

            }

        }
        if (!ok) { //재방문이 되지않고 종료된 경우.
            cnt++; 
        }
        ok = false; // 초기화

    }

    cout << cnt;
}
