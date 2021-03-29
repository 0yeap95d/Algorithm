#include <iostream>
#include <queue>
using namespace std;

struct Monkey {
	int x;
	int y;
	int m;
	int cnt;
};

int K, W, H;
int map[201][201];
bool visited[201][201][30];
int dx[12] = { 0, 0, -1, 1, -2, -1, 1, 2, 2, 1, -1, -2 };
int dy[12] = { -1, 1, 0, 0, 1, 2, 2, 1, -1, -2, -2, -1 };

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// Ƚ�� K, ���� W, ���� H
	cin >> K >> W >> H;
	
	// �������� �������� ���� ��
	if (W == 1 && H == 1) {
		cout << 0;
		return 0;
	}

	// ������ �Է�
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) cin >> map[i][j];
	}


	queue<Monkey> que;
	visited[0][0][0] = true;
	que.push({ 0, 0, 0, 0 });

	while (!que.empty()) {

		int x = que.front().x;
		int y = que.front().y;
		int m = que.front().m;
		int cnt = que.front().cnt;
		que.pop();

		// �� �������� K�� ��������� �����Ž���� ���� 
		int limit = 12;
		if (m >= K) limit = 4;

		for (int i = 0; i < limit; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			// ���� üũ
			if (nx < 0 || nx >= H || ny < 0 || ny >= W || map[nx][ny] == 1) continue;

			// ������, ���� ��� �� ����
			if (nx == H - 1 && ny == W - 1) {
				cout << cnt + 1;
				return 0;
			}

			// ������ ������
			if (i < 4) {
				if (visited[nx][ny][m]) continue;
				visited[nx][ny][m] = true;
				que.push({ nx, ny, m, cnt + 1 });
			}

			// �� ������
			else {
				if (visited[nx][ny][m + 1]) continue;
				visited[nx][ny][m + 1] = true;
				que.push({ nx, ny, m + 1, cnt + 1 });
			}
		}
	}

	// ���������� �� �� ���� ���
	cout << -1;

	return 0;
}