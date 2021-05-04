#include <iostream>
#include <queue>
#include <map>
#define SIZE 101
using namespace std;

int N, M;
map<int, int> ladder, snake;

void init() {
	cin >> N >> M;

	int x, y;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		ladder[x] = y;
	}

	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		snake[x] = y;
	}
}

int BFS() {
	queue<pair<int, int>> que;
	bool visited[SIZE] = { false, };

	que.push({ 1, 0 });
	visited[1] = true;

	while (!que.empty()) {
		int pos = que.front().first;
		int cnt = que.front().second;
		que.pop();

		for (int i = 1; i <= 6; i++) {
			int nextPos = pos + i;
			if (ladder[nextPos] != 0) nextPos = ladder[nextPos];
			else if (snake[nextPos] != 0) nextPos = snake[nextPos];
			
			if (nextPos < 1 || nextPos > 100 || visited[nextPos]) continue;
			if (nextPos == 100) return cnt + 1;
			que.push({ nextPos, cnt + 1 });
			visited[nextPos] = true;
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	init();
	cout << BFS();

	return 0;
}