#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#define MAX_V 100001
using namespace std;

int N, K;
bool visited[MAX_V * 2];
int root[MAX_V * 2];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> K;

	queue<int> que;
	que.push(N);
	visited[N] = true;
	root[N] = -1;

	int pos;
	while (!que.empty()) {
		pos = que.front();
		que.pop();

		int idx = pos - 1;
		if (idx >= 0 && !visited[idx]) {
			que.push(idx);
			visited[idx] = true;
			root[idx] = pos;
		}

		idx = pos + 1;
		if (idx < MAX_V && !visited[idx]) {
			que.push(idx);
			visited[idx] = true;
			root[idx] = pos;
		}

		idx = pos * 2;
		if (idx < MAX_V * 2 && !visited[idx]) {
			que.push(idx);
			visited[idx] = true;
			root[idx] = pos;
		}

		if (visited[K]) break;
	}
	
	stack<int> ans;
	ans.push(K);

	int next = root[K];
	while (next != -1) {
		ans.push(next);
		next = root[next];
	}

	cout << ans.size() - 1 << "\n";
	while (!ans.empty()) {
		cout << ans.top() << " ";
		ans.pop();
	}

	return 0;
}