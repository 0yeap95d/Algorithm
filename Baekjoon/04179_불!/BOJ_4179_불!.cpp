#include <iostream>
#include <queue>
#define SIZE 1001
using namespace std;

int R, C;
char maze[SIZE][SIZE];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

queue<pair<int, int>> JH, nextJH, fire, nextFire;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> R >> C;

	// �̷� ���� �Է�
	for (int r = 0; r < R; r++) {
		cin >> maze[r];
		for (int c = 0; c < C; c++) {
			if (maze[r][c] == '.') continue;
			if (maze[r][c] == 'F') nextFire.push({ r, c });
			else if (maze[r][c] == 'J') nextJH.push({ r, c });
		}
	}

	// Ż��
	bool isEscape = false;
	int time = 0;
	while (!nextJH.empty()) {
		time++;

		// ���� �� ��ġ queue�� ���
		while (!nextFire.empty()) {
			fire.push(nextFire.front());
			nextFire.pop();
		}

		// ���� ���� ��ġ queue�� ���
		while (!nextJH.empty()) {
			JH.push(nextJH.front());
			nextJH.pop();
		}

		// �� �̵�
		while (!fire.empty()) {
			int x = fire.front().first;
			int y = fire.front().second;
			fire.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
				if (maze[nx][ny] == '#' || maze[nx][ny] == 'F') continue;

				maze[nx][ny] = 'F';
				nextFire.push({ nx, ny });
			}
		}

		// ���� �̵�
		while (!JH.empty()) {
			int x = JH.front().first;
			int y = JH.front().second;
			JH.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				// Ż�� ����
				if (nx < 0 || nx >= R || ny < 0 || ny >= C) {
					isEscape = true;
					break;
				}
				if (maze[nx][ny] != '.') continue;

				maze[nx][ny] = 'v';
				nextJH.push({ nx, ny });
			}
			if (isEscape) break;
		}
		if (isEscape) break;
	}

	// ���� ���
	if (isEscape) cout << time;
	else cout << "IMPOSSIBLE";

	return 0;
}