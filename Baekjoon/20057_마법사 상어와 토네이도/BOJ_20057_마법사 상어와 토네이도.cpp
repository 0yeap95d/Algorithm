#include <iostream>
#include <vector>
using namespace std;

int N, ans;
vector<vector<int>> map;
vector<vector<bool>> visited;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

// 범위체크
bool isInner(int nx, int ny) {
	return !(nx < 0 || nx >= N || ny < 0 || ny >= N);
}

// 다음 바람이 가야할 방향
int getWindDir(int x, int y, int dir) {
	int nx, ny, ret;
	if (dir == 0) nx = x + 1, ny = y, ret = 1;
	else if (dir == 1) nx = x, ny = y + 1, ret = 2;
	else if (dir == 2) nx = x - 1, ny = y, ret = 3;
	else nx = x, ny = y - 1, ret = 0;
	
	if (visited[nx][ny]) return dir;
	else {
		x = nx;
		y = ny;
		return ret;
	}
}

void flutterSand(int nx, int ny, int value) {
	if (isInner(nx, ny)) map[nx][ny] += value;
	else ans += value;
}

void moveWind(int x, int y, int dir) {
	int sand, nx, ny, value, sum = 0;

	// 다음 바람 위치
	nx = x + dx[dir], ny = y + dy[dir];
	sand = map[nx][ny];

	value = sand / 100;
	sum += value * 2;
	flutterSand(x + dy[dir], y + dx[dir], value);
	flutterSand(x - dy[dir], y - dx[dir], value);

	value = sand * 7 / 100;
	sum += value * 2;
	flutterSand(x + dx[dir] + dy[dir], y + dy[dir] + dx[dir], value);
	flutterSand(x + dx[dir] - dy[dir], y + dy[dir] - dx[dir], value);

	value = sand * 2 / 100;
	sum += value * 2;
	flutterSand(x + dx[dir] + 2 * dy[dir], y + dy[dir] + 2 * dx[dir], value);
	flutterSand(x + dx[dir] - 2 * dy[dir], y + dy[dir] - 2 * dx[dir], value);

	value = sand * 10 / 100;
	sum += value * 2;
	flutterSand(x + 2 * dx[dir] + dy[dir], y + 2 * dy[dir] + dx[dir], value);
	flutterSand(x + 2 * dx[dir] - dy[dir], y + 2 * dy[dir] - dx[dir], value);

	value = sand * 5 / 100;
	sum += value;
	flutterSand(x + 3 * dx[dir], y + 3 * dy[dir], value);
	flutterSand(x + 2 * dx[dir], y + 2 * dy[dir], sand - sum);

	map[nx][ny] = 0;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	
	cin >> N;
	map.assign(N, vector<int>(N, 0));
	visited.assign(N, vector<bool>(N, 0));

	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			cin >> map[i][j];

	// 토네이도 위치, 방향
	int x, y, dir = 0;
	x = y = N / 2;

	while (1) {
		moveWind(x, y, dir);
		visited[x][y] = true;
		x += dx[dir], y += dy[dir];
		if (x == 0 && y == 0) break;
		dir = getWindDir(x, y, dir);
	}

	cout << ans;
	
	return 0;
}