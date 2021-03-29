#include <iostream>
#include <queue>
#include <cstring>
#include <cmath>
#define SIZE 101
#define INF 987654321
using namespace std;

int R, C;
char Board[SIZE][SIZE];
pair<int, int> PosI;
queue<pair<int, int>> PosR, NextR, Destroy;
string Command;

int dx[10] = { 0, 1, 1, 1, 0, 0, 0, -1, -1, -1 };
int dy[10] = { 0, -1, 0, 1, -1, 0, 1, -1, 0, 1 };

// 거리 구하기
int get_Distance(pair<int, int> p1, pair<int, int> p2) {
	return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);


	// 입력
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> Board[i][j];
			if (Board[i][j] == 'I') PosI = { i, j };
		}
	}
	cin >> Command;

	int cnt = 0;
	bool isEnd = false;
	for (char com : Command) {

		// 종수 아두이노
		int di = com - '0';
		int jx = PosI.first + dx[di];
		int jy = PosI.second + dy[di];
		cnt++;

		if (Board[jx][jy] == 'R') {
			isEnd = true;
			break;
		}

		Board[PosI.first][PosI.second] = '.';
		Board[jx][jy] = 'I';
		PosI = { jx, jy };
		

		// 미친 아두이노
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++)
				if (Board[i][j] == 'R') PosR.push({ i, j });
		}

		while (!PosR.empty()) {
			int x = PosR.front().first;
			int y = PosR.front().second;
			PosR.pop();

			// 이동할 좌표 정하기
			int mx, my, md = INF;
			for (int i = 1; i <= 9; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;

				int nd = get_Distance(PosI, { nx, ny });
				if (md > nd) mx = nx, my = ny, md = nd;
			}

			if (Board[mx][my] == 'I') {
				isEnd = true;
				break;
			}

			// 이동할 좌표 저장
			NextR.push({ mx, my });
			Board[x][y] = '.';
		}

		if (isEnd) break;

		// 이동
		while (!NextR.empty()) {
			int nx = NextR.front().first;
			int ny = NextR.front().second;
			NextR.pop();
			if (Board[nx][ny] == 'R') Destroy.push({ nx, ny });
			Board[nx][ny] = 'R';
		}

		// 파괴
		while (!Destroy.empty()) {
			int x = Destroy.front().first;
			int y = Destroy.front().second;
			Destroy.pop();
			Board[x][y] = '.';
		}
	}


	// 출력
	if (!isEnd) {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) cout << Board[i][j];
			cout << "\n";
		}
	}
	else cout << "kraj " << cnt;


	return 0;
}