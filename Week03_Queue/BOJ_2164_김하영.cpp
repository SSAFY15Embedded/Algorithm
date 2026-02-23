#include <iostream>
#include <queue>
using namespace std;

int main() {
	int N;
	cin >> N;
	queue<int>q;

	while (!q.empty()) {
		// 맨 앞 노드 추출
		queue<int>nq;
		int a = q.front(); q.pop();
		for (int i = a + 2; i < N; i++) {
			nq.push(i);
		}
		nq.push(a + 1);
	}
}
