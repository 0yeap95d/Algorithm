#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, K;
bool map[101][101];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int main() {

	// 세로 길이 N, 가로 길이 M, 음식물 쓰레기 개수 K
	cin >> N >> M >> K;

	// 음식물 좌표 정보 입력
	int r, c;
	for (int i = 0; i < K; i++) {
		cin >> r >> c;
		map[r - 1][c - 1] = true;
	}

	// BFS를 통해 모여있는 쓰레기 크기 카운팅
	queue<pair<int, int>> que;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!map[i][j]) continue;

			int cnt = 0;
			map[i][j] = false;
			que.push({ i, j });

			while (!que.empty()) {
				int x = que.front().first;
				int y = que.front().second;
				que.pop();
				cnt++;

				for (int di = 0; di < 4; di++) {
					int nx = x + dx[di];
					int ny = y + dy[di];

					// 범위 체크
					if (nx < 0 || nx >= N || ny < 0 || ny >= M || !map[nx][ny]) continue;

					map[nx][ny] = false;
					que.push({ nx, ny });
				}
			}

			// ans 업데이트
			ans = max(ans, cnt);
		}
	}

	// 정답 출력
	cout << ans;

	return 0;
}