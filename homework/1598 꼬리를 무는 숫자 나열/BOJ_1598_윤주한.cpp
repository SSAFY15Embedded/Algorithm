#include <iostream>
#define ABS(x) (((x) < 0) ? (-(x)) : (x))
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int y1 = (N - 1) % 4;
    int x1 = (N - 1) / 4;
    int y2 = (M - 1) % 4;
    int x2 = (M - 1) / 4;

    int ans = ABS(y1 - y2) + ABS(x1 - x2);
    cout << ans;
    
    return 0;
}
