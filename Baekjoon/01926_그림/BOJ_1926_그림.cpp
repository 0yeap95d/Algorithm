#include <iostream>
#include <queue>
#include <algorithm>
#define SIZE 505
using namespace std;

int N, M, cntDraw, Area;
bool paper[SIZE][SIZE];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> M;

	// 그림 정보 입력
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> paper[i][j];
		}
	}

	
	queue<pair<int, int>> que;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!paper[i][j]) continue;
			que.push({ i, j });
			paper[i][j] = false;
			cntDraw++;

			int area = 1;
			while (!que.empty()) {
				int x = que.front().first;
				int y = que.front().second;
				que.pop();

				for (int dir = 0; dir < 4; dir++) {
					int nx = x + dx[dir];
					int ny = y + dy[dir];
					if (nx < 0 || nx >= N || ny < 0 || ny >= M || !paper[nx][ny]) continue;

					que.push({ nx, ny });
					paper[nx][ny] = false;
					area++;
				}
			}
			Area = max(Area, area);
		}
	}

	cout << cntDraw << "\n" << Area;

	return 0;
}