#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int x, cnt;	
	vector<int> trace;
	queue<int> que;

	cin >> x;
	trace.resize(x + 1);
	que.push(x);
	trace[x] = x;
	cnt = 0;

	while (trace[1] == 0) {
		x = que.front();
		que.pop();
		if (x == 1) break;

		if (x % 3 == 0 && trace[x / 3] == 0) {
			que.push(x / 3);
			trace[x / 3] = x;
		}
		if (x % 2 == 0 && trace[x / 2] == 0) {
			que.push(x / 2);
			trace[x / 2] = x;
		}
		if (x - 1 >= 1 && trace[x - 1] == 0) {
			que.push(x - 1);
			trace[x - 1] = x;
		}
	}

	// 역추적
	int idx = 1;
	stack<int> answer;
	while (trace[idx] != idx) {
		answer.push(trace[idx]);
		idx = trace[idx];
	}

	// 정답 출력
	cout << answer.size() << "\n";
	while (!answer.empty()) {
		cout << answer.top() << ' ';
		answer.pop();
	}
	cout << 1;

	return 0;
}