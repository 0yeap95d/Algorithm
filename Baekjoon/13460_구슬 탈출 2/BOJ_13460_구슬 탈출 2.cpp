#include <iostream>
#include <vector>
using namespace std;

struct Pos {
	int x;
	int y;

	Pos() {}
	Pos(int x, int y) : x(x), y(y) {}
};

const int dx[4] = { 0, 0, -1, 1 };
const int dy[4] = { -1, 1, 0, 0 };

int n, m, ans = 11;
Pos red, blue, target;
vector<vector<int>> map;

void dfs(Pos red, Pos blue, int dir, int move) {
	// hole in or move > 10
	if (move >= ans) return;



	int cnt_b, cnt_r, pre_b, pre_r;
	cnt_b = cnt_r = pre_b = pre_r = 0;

	bool goal_b, goal_r;
	goal_b = goal_r = false;

	int nx, ny;
	while (1) {
		// move blue, cnt_b
		if (!goal_b) {
			nx = blue.x + dx[dir];
			ny = blue.y + dy[dir];
			if ((0 <= nx && nx < n) && (0 <= ny && ny < m) && map[nx][ny] <= 0) {
				cnt_b++;
				map[blue.x][blue.y] = 0;
				if (map[nx][ny] == -1) {
					goal_b = true;
					continue;
				}
				map[nx][ny] = 4;
				blue.x = nx;
				blue.y = ny;
			}
		}

		// move red, cnt_r
		if (!goal_r) {
			nx = red.x + dx[dir];
			ny = red.y + dy[dir];
			if ((0 <= nx && nx < n) && (0 <= ny && ny < m) && map[nx][ny] <= 0) {
				cnt_r++;
				map[red.x][red.y] = 0;
				if (map[nx][ny] == -1) {
					goal_r = true;
					continue;
				}
				map[nx][ny] = 3;
				red.x = nx;
				red.y = ny;
			}
		}

		// all stop : break;
		if (pre_b == cnt_b && pre_r == cnt_r) break;
		pre_b = cnt_b;
		pre_r = cnt_r;
	}

	// cnt_b == cnt_r : return;
	if (goal_b && goal_r) {
		return;
	} 
	else if (goal_r) {
		ans = move;
		return;
	}
	else if (goal_b) return;
	

	for (int i = 0; i < 4; i++) {
		dfs(red, blue, i, move + 1);
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < m; y++) {
				if (map[x][y] > 2) map[x][y] = 0;
			}
		}
		map[target.x][target.y] = -1;
		map[red.x][red.y] = 3;
		map[blue.x][blue.y] = 4;
	}
}

int main() {
	cin >> n >> m;

	map.assign(n, vector<int>(m, 0));

	char c;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c;
			if (c == '#') map[i][j] = 1;
			else if (c == 'O') {
				map[i][j] = -1;
				target = Pos(i, j);
			}
			else if (c == 'R') {
				map[i][j] = 3;
				red = Pos(i, j);
			}
			else if (c == 'B') {
				map[i][j] = 4;
				blue = Pos(i, j);
			}
			else continue;
		}
	}

	for (int i = 0; i < 4; i++) {
		dfs(red, blue, i, 1);
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < m; y++) {
				if (map[x][y] > 2) map[x][y] = 0;
			}
		}
		map[target.x][target.y] = -1;
		map[red.x][red.y] = 3;
		map[blue.x][blue.y] = 4;
	}
	if (ans == 11) ans = -1;

	cout << ans;

	return 0;
}