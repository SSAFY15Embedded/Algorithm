#include <iostream>
using namespace std;

int N;
int num[12];
int arr[4];
int MAX = -21e8;
int MIN = 21e8;

void func(int idx, int result) {
    if (idx == N) {
        if (result > MAX) MAX = result;
        if (result < MIN) MIN = result;
        return;
    }

    if (arr[0] > 0) {
        arr[0]--;
        func(idx + 1, result + num[idx]);
        arr[0]++;
    }

    if (arr[1] > 0) {
        arr[1]--;
        func(idx + 1, result - num[idx]);
        arr[1]++;
    }

    if (arr[2] > 0) {
        arr[2]--;
        func(idx + 1, result * num[idx]);
        arr[2]++;
    }

    if (arr[3] > 0) {
        arr[3]--;
        func(idx + 1, result / num[idx]);
        arr[3]++;
    }
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }

    for (int i = 0; i < 4; i++) {
        cin >> arr[i];
    }

    func(1, num[0]);

    cout << MAX << endl;
    cout << MIN << endl;
}
