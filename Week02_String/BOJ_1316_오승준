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
            if (visited[temp - 0]) {
                ok = true;
                break;
            } // 그룹단어 존재 시 나가기.
            visited[temp - 0] = 1;
            for (int k = j + 1; k < s.length(); k++) {

                if (temp != s[k]) { //그전값과 다르다면 나가기.
                    j = k; //
                 
                    break;

                }
                j = k;

            }

        }
        if (!ok) {
            cnt++;
        }
        ok = false;

    }

    cout << cnt;
}
