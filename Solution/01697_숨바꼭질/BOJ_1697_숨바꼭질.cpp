#include <iostream>
#include <queue>
using namespace std;

bool visit[200001];

int main() {
	int n, k, Answer;
	cin >> n >> k;
	Answer = k - n;

	queue<pair<int, int>> bfs;
	bfs.push(make_pair(n, 0));
	visit[n] = true;

	int key, value;
	while (!bfs.empty()) {
		key = bfs.front().first;
		value = bfs.front().second;
		if (key == k) {
			Answer = value;
			break;
		}

		if (key * 2 < 200001 && !visit[key * 2] && (key * 2 - k) + value + 1 < Answer) {
			bfs.push(make_pair(key * 2, value + 1));
			visit[key * 2] = true;
		}
		if (!visit[key + 1]) {
			bfs.push(make_pair(key + 1, value + 1));
			visit[key + 1] = true;
		}
		if (key - 1 >= 0 && !visit[key - 1]) {
			bfs.push(make_pair(key - 1, value + 1));
			visit[key - 1] = true;
		}

		bfs.pop();
	}

	cout << Answer;
	return 0;
}