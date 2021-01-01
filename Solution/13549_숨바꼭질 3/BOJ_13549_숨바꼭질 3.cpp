#include <iostream>
#include <vector>
#include <queue>
#define SIZE 100001
using namespace std;

int N, K;
vector<int> visited;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// 입력 | 수빈 N, 동생 K
	cin >> N >> K;
	visited.assign(SIZE * 2, SIZE);

	queue<pair<int, int>> que;
	que.push({ N, 0 });
	visited[N] = 0;

	while (!que.empty()) {
		int pos = que.front().first;
		int time = que.front().second;
		que.pop();

		// 한 칸 뒤로 이동
		if (pos - 1 >= 0 && visited[pos - 1] > time + 1) {
			if (visited[K] != SIZE && time + 1 > visited[K]) continue;
			que.push({ pos - 1, time + 1 });
			visited[pos - 1] = time + 1;
		}

		// 한 칸 앞으로 이동
		if (pos + 1 < SIZE && visited[pos + 1] > time + 1) {
			if (visited[K] != SIZE && time + 1 > visited[K]) continue;
			que.push({ pos + 1, time + 1 });
			visited[pos + 1] = time + 1;
		}

		// 순간이동 두 배 앞으로 이동
		if (pos * 2 < SIZE * 2 && visited[pos * 2] > time) {
			if (visited[K] != SIZE && pos * 2 - K >= visited[K]) continue;
			que.push({ pos * 2, time });
			visited[pos * 2] = time;
		}
	}

	cout << visited[K];

	return 0;
}