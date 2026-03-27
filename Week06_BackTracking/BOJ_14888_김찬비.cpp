#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> path;
// + - * /
vector<int> nums;
int op[4]; // 차례대로 덧셈(+)의 개수, 뺄셈(-)의 개수, 곱셈(×)의 개수, 나눗셈(÷)의 개수이다.
vector<int> operators;
int MIN = 21e8, MAX = -21e8;
int total;
int visited[11];

// N개의 수열
// N - 1개의 연산자

void func(int n) {
	// 1. 기저 조건
	if (n == N - 1) {
		total = nums[0];
		for (int i = 1; i < N; i++) {
			switch (operators[path[i - 1]]) {
			case 0:
				total += nums[i];
				break;
			case 1:
				total -= nums[i];
				break;
			case 2:
				total *= nums[i];
				break;
			case 3:
				total /= nums[i];
				break;
			}
		}

		if (total > MAX)
			MAX = total;
		if (total < MIN)
			MIN = total;
		total = 0;
		return;
	}

	// 2. 재귀 조건
	for (int i = 0; i < operators.size(); i++) {
		// 순열

		if (visited[i] != 0)
			continue;

		visited[i] = 1;
		path.push_back(i);
		func(n + 1);
		path.pop_back();
		visited[i] = 0;
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		nums.push_back(n);
	}

	for (int i = 0; i < 4; i++) {
		cin >> op[i];
		for (int j = 0; j < op[i]; j++)
			operators.push_back(i);
	}

	func(0);

	cout << MAX << endl;
	cout << MIN;
}
