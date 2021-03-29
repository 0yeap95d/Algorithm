#include <iostream>
#include <vector>
#include <queue>
#define SIZE 102
using namespace std;

int N, M, Ans;
bool room[SIZE][SIZE];
bool visited[SIZE][SIZE];
vector<pair<int, int>> button[SIZE][SIZE];
queue<pair<int, int>> que;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// 데이터 입력
	cin >> N >> M;
	
	int x, y, a, b;
	for (int i = 0; i < M; i++) {
		cin >> x >> y >> a >> b;
		button[x][y].push_back({ a, b });
	}

	que.push({ 1, 1 });
	visited[1][1] = true;
	room[1][1] = true;

	while (!que.empty()) {
		// 방문
		int cx = que.front().first;
		int cy = que.front().second;
		que.pop();

		// 불 켜기
		for (auto pos : button[cx][cy]) {
			room[pos.first][pos.second] = true;

			if (visited[pos.first][pos.second]) continue;

			// 주위에 방문된 곳이 있다면 Queue에 추가
			for (int i = 0; i < 4; i++) {
				int nx = pos.first + dx[i];
				int ny = pos.second + dy[i];

				if (visited[nx][ny]) {
					que.push(pos);
					visited[pos.first][pos.second] = true;
					break;
				}
			}
		}

		// 이동
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			// 방문체크, 불 꺼진 방 체크 
			if (visited[nx][ny] || !room[nx][ny]) continue;

			que.push({ nx, ny });
			visited[nx][ny] = true;
		}
	}

	// 불 켜진 방 카운트
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) 
			if (room[i][j]) Ans++;
	}

	// 정답 출력
	cout << Ans;

	return 0;
}