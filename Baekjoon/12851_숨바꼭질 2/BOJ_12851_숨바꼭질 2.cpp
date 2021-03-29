#include <iostream>
#include <queue>
using namespace std;

int visited[2][200001] = { 0, };

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// N: 수빈위치, K: 동생위치
	int N, K;
	cin >> N >> K;

	queue<pair<int, int>> que;
	que.push({ N, 0 });

	// 0: 가장 빠른 시간, 1: 방법의 수
	visited[0][N] = 0;
	visited[1][N] = 1;

	int pos, curTime = 0;

	while (!que.empty()) {
		pos = que.front().first;
		curTime = que.front().second;
		que.pop();

		if (visited[1][K] != 0 && visited[0][K] < curTime) break;

		// pos - 1
		int idx = pos - 1;
		if (idx >= 0) {
			if (visited[0][idx] == 0) {
				visited[0][idx] = curTime + 1;
				que.push({ idx, curTime + 1 });
			}
			if (visited[0][idx] == curTime + 1) visited[1][idx] += visited[1][pos];
		}

		// pos + 1
		idx = pos + 1;
		if (idx < 100001) {
			if (visited[0][idx] == 0) {
				visited[0][idx] = curTime + 1;
				que.push({ idx, curTime + 1 });
			}
			if (visited[0][idx] == curTime + 1) visited[1][idx] += visited[1][pos];
		}

		// pos * 2
		idx = pos * 2;
		if (idx < 200001) {
			if (visited[0][idx] == 0) {
				visited[0][idx] = curTime + 1;
				que.push({ idx, curTime + 1 });
			}
			if (visited[0][idx] == curTime + 1) visited[1][idx] += visited[1][pos];
		}

	}

	cout << visited[0][K] << "\n" << visited[1][K];

	return 0;
}