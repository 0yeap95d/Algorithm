#include <iostream>
#include <string>
#include <queue>
#include <vector>
#define SIZE 101
using namespace std;

int N, M;
int map[SIZE][SIZE];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N;
	string inp;

	for (int i = 0; i < N; i++) {
		cin >> inp;
		for (int j = 0; j < M; j++) {
			if (inp[j] == '1') map[i][j] = -1;
			else map[i][j] = 0;
		}
	}

	queue<pair<int, int>> next;
	next.push(make_pair(0, 0));
	map[0][0] = 1;

	queue<pair<int, int>> que;
	int cnt = 0;
	while (!next.empty()) {
		cnt++;
		while(!next.empty()) {
			que.push(next.front());
			next.pop();
		}
		while (!que.empty()) {
			int x = que.front().first;
			int y = que.front().second;
			que.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || nx >= N || ny < 0 || ny >= M || map[nx][ny] > 0) continue;
				if (map[nx][ny] == 0) {
					que.push(make_pair(nx, ny));
					map[nx][ny] = cnt;
				}
				else if (map[nx][ny] == -1) {
					next.push(make_pair(nx, ny));
					map[nx][ny] = cnt + 1;
				}
			}
		}
	}

	int ans = map[N - 1][M - 1] - 1;
	cout << ans;

	return 0;
}