#include <iostream>
#include <queue>
using namespace std;

int N, M;
int cheese[102][102];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

// 외부공기, 내부 공간 구분
void divideArea() {

	// 0: 내부공간, 2: 외부공기
	queue<pair<int, int>> que;
	cheese[0][0] = 2;
	que.push({ 0, 0 });

	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx > N + 1 || ny < 0 || ny > M + 1 || cheese[nx][ny] != 0) continue;
			cheese[nx][ny] = 2;
			que.push({ nx, ny });
		}
	}

}

// 치즈 녹음
bool meltCheese() {

	queue<pair<int, int>> que;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {

			if (cheese[i][j] != 1) continue;

			// 네 방향 체크
			int cnt = 0;
			for (int d = 0; d < 4; d++) {
				int nx = i + dx[d];
				int ny = j + dy[d];
				if (cheese[nx][ny] == 2) cnt++;
			}

			// 녹을 치즈 저장
			if (cnt >= 2) que.push({ i, j });

		}
	}

	// 더 이상 녹일 치즈가 없을 때
	if (que.empty()) return false;

	// 치즈를 녹이고 내부 공간 체크
	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();

		cheese[x][y] = 2;

		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (cheese[nx][ny] == 0) que.push({ nx, ny });
		}
	}

	return true;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// 세로 N, 가로 M 입력
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) cin >> cheese[i][j];
	}

	divideArea();

	int ans = 0;
	while (meltCheese()) ans++;

	cout << ans;

	return 0;
}