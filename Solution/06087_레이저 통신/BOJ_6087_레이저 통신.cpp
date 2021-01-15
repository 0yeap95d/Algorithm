#include <iostream>
#include <queue>
#include <algorithm>
#define SIZE 101
#define INF 987654321
using namespace std;

struct Laser{
	int x;
	int y;
	int dir;
	int cnt;
};

int W, H;
char map[SIZE][SIZE];
int visited[SIZE][SIZE];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

queue<Laser> que;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> W >> H;

	// ���� �Է�
	bool isFirst = true;
	for (int i = 0; i < H; i++) {
		cin >> map[i];
		for (int j = 0; j < W; j++) {
			visited[i][j] = INF;
			if (map[i][j] == '*') visited[i][j] = -1;

			// ó�� ������ �Է¹޾��� ��
			if (map[i][j] == 'C' && isFirst) {
				isFirst = false;
				map[i][j] = '*';
				visited[i][j] = 0;
				que.push({ i, j, -1, -1 });
			}
		}
	}

	int ans = INF;
	while (!que.empty()) {
		Laser laser = que.front();
		que.pop();

		// ������ ����
		if (map[laser.x][laser.y] == 'C') {
			ans = min(ans, laser.cnt);
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int nx = laser.x + dx[i];
			int ny = laser.y + dy[i];

			// ���� üũ
			if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;

			// ������ �ٲ��� �ʴ� ���
			if (laser.dir == i) {
				if (laser.cnt > visited[nx][ny]) continue;
				visited[nx][ny] = laser.cnt;
				que.push({ nx, ny, i, laser.cnt });
			}

			// ������ �ٲ�� ���
			else {
				if (laser.cnt + 1 > visited[nx][ny]) continue;
				visited[nx][ny] = laser.cnt + 1;
				que.push({ nx, ny, i, laser.cnt + 1 });
			}
		}
	}

	// ���� ���
	cout << ans;

	return 0;
}