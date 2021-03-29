#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// 세로 M, 가로 N
	int N, M;
	cin >> M >> N;

	// 병사 입력
	string inp;
	vector<vector<int>> map(N, vector<int>(M, 0));
	vector<vector<bool>> visited(N, vector<bool>(M, false));
	for (int i = 0; i < N; i++) {
		cin >> inp;
		for (int j = 0; j < M; j++) map[i][j] = inp[j];
	}

	int cntW, cntB;
	cntW = cntB = 0;

	queue<pair<int, int>> que;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j]) continue;
	
			visited[i][j] = true;
			que.push({ i, j });

			int cnt = 1;
			while (!que.empty()) {
				int x = que.front().first;
				int y = que.front().second;
				que.pop();

				for (int d = 0; d < 4; d++) {
					int nx = x + dx[d];
					int ny = y + dy[d];

					// 범위, 방문 체크
					if (nx < 0 || nx >= N || ny < 0 || ny >= M || visited[nx][ny] || map[nx][ny] != map[i][j]) continue;
					
					cnt++;
					visited[nx][ny] = true;
					que.push({ nx, ny });
				}
			}

			// 전투력 측정
			if (map[i][j] == 'W') cntW += cnt * cnt;
			else if (map[i][j] == 'B') cntB += cnt * cnt;
		}
	}

	// 정답 출력
	cout << cntW << " " << cntB;

	return 0;
}