#include <iostream>
#include <queue>
#define endl "\n"
using namespace std;

struct Pos {
	int x;
	int y;
	int cnt;

	Pos(int x, int y, int c) 
		: x(x), y(y), cnt(c) {};
};

const int dx[4] = { 0, 0, -1, 1 };
const int dy[4] = { -1, 1, 0, 0 }; 

char map[51][51];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// ÀÔ·Â
	int x, y;
	cin >> x >> y;
	queue<Pos> water, move;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cin >> map[i][j];
			if (map[i][j] == '*') water.push(Pos(i, j, 0));
			if (map[i][j] == 'S') move.push(Pos(i, j, 0));
		}
	}


	int ans = 0;
	bool isAns = false;
	while (!move.empty()) {
		
		// È«¼ö
		while (!water.empty()) {
			Pos w = water.front();
			if (w.cnt > ans) break;
			water.pop();

			for (int i = 0; i < 4; i++) {
				int nx = w.x + dx[i];
				int ny = w.y + dy[i];
				if (nx < 0 || nx >= x || ny < 0 || ny >= y) continue;
				if (map[nx][ny] == 'D' || map[nx][ny] == 'X' || map[nx][ny] == '*') continue;
				map[nx][ny] = '*';
				water.push(Pos(nx, ny, w.cnt + 1));
			}
		}

		// °í½¿µµÄ¡ ÀÌµ¿
		while (!move.empty()) {
			Pos m = move.front();
			if (m.cnt > ans) break;
			move.pop();

			for (int i = 0; i < 4; i++) {
				int nx = m.x + dx[i];
				int ny = m.y + dy[i];
				if (nx < 0 || nx >= x || ny < 0 || ny >= y) continue;
				if (map[nx][ny] == '*' || map[nx][ny] == 'X' || map[nx][ny] == 'S') continue;
				if (map[nx][ny] == 'D') {
					isAns = true;
					break;
				}
				map[nx][ny] = 'S';
				move.push(Pos(nx, ny, m.cnt + 1));
			}

			if (isAns) break;
		}

		ans++;
		if (isAns) break;
	}

	if (isAns) cout << ans;
	else cout << "KAKTUS";

	return 0;
}