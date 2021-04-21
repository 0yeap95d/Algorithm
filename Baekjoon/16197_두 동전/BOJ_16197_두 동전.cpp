#include <iostream>
#include <queue>
#define SIZE 21
using namespace std;

struct Coin {
	int x1;
	int y1;
	int x2;
	int y2;
	int count;
};

int N, M, Answer = -1;
char Board[SIZE][SIZE];
bool visited[SIZE][SIZE][SIZE][SIZE];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

bool isDrop(int x, int y) {
	if (x < 0 || x >= N || y < 0 || y >= M) return true;
	return false;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> M;
	Coin coinPos = { -1, -1, -1, -1, 0 };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> Board[i][j];
			if (Board[i][j] == 'o') {
				if (coinPos.x1 == -1) coinPos.x1 = i, coinPos.y1 = j;
				else coinPos.x2 = i, coinPos.y2 = j;
			}
		}
	}

	queue<Coin> que;
	que.push(coinPos);
	visited[coinPos.x1][coinPos.y1][coinPos.x2][coinPos.y2] = true;

	while (!que.empty()) {
		Coin coin = que.front();
		que.pop();
		if (coin.count == 10) continue;

		for (int i = 0; i < 4; i++) {
			int nx1 = coin.x1 + dx[i];
			int ny1 = coin.y1 + dy[i];
			int nx2 = coin.x2 + dx[i];
			int ny2 = coin.y2 + dy[i];

			if (Board[nx1][ny1] == '#') nx1 -= dx[i], ny1 -= dy[i];
			if (Board[nx2][ny2] == '#') nx2 -= dx[i], ny2 -= dy[i];
			

			if (isDrop(nx1, ny1) && isDrop(nx2, ny2)) continue;
			else if (isDrop(nx1, ny1) || isDrop(nx2, ny2)) {
				Answer = coin.count + 1;
				break;
			}

			if (visited[nx1][ny1][nx2][ny2]) continue;
			que.push({ nx1, ny1, nx2, ny2, coin.count + 1 });
			visited[nx1][ny1][nx2][ny2] = true;
		}

		if (Answer != -1) break;
	}
	cout << Answer;

	return 0;
}