#include <iostream>
#include <queue>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N, inp;
	priority_queue<int> que;

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> inp;
			que.push(-inp);
			while (que.size() > N) que.pop();
		}
	}

	cout << -que.top();

	return 0;
}