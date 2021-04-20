#include <iostream>
#include <queue>
#define SIZE 201
using namespace std;

int R, C, N;
char board[SIZE][SIZE];
int timer[SIZE][SIZE];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

void printTimer() {
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			if (timer[r][c] == 0) cout << '.';
			else cout << 'O';
		}
		cout << '\n';
	}
}

void BFS() {

	queue<pair<int, int>> que;

	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			if (timer[r][c] == 0) timer[r][c] = 3;
			else if (timer[r][c] == 1) que.push({ r, c });
			else timer[r][c]--;
		}
	}

	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		timer[x][y] = 0;
		que.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
			timer[nx][ny] = 0;
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> R >> C >> N;
	char inp;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> inp;
			if (inp == 'O') timer[i][j] = 2;
		}
	}

	while (N-- > 1) BFS();
	
	printTimer();
	
	return 0;
}