#include <iostream>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

int Ans = INF;

bool Block[5][5][5];
bool Cube[5][5][5];
bool visited[5];

int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

struct Pos {
	int z;
	int x;
	int y;
	int time;
};

// 큐브에서 시작과 끝점의 최소거리를 구하는 부분
void Exit_Cube() {
	if (!Cube[0][0][0] || !Cube[4][4][4]) return;

	bool Maze[5][5][5];
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++)
				Maze[i][j][k] = Cube[i][j][k];
		}
	}

	queue<Pos> que;
	que.push({0, 0, 0, 0});
	Maze[0][0][0] = false;

	bool isAns = false;
	while (!que.empty() && !isAns) {
		Pos pos = que.front();
		que.pop();
		if (Ans <= pos.time) break;

		for (int i = 0; i < 6; i++) {
			int nz = pos.z + dz[i];
			int nx = pos.x + dx[i];
			int ny = pos.y + dy[i];

			if (nz < 0 || nz >= 5 || nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || !Maze[nz][nx][ny]) continue;
			if (nz == 4 && nx == 4 && ny == 4) {
				Ans = min(Ans, pos.time + 1);
				isAns = true;
				break;
			}

			que.push({ nz, nx, ny, pos.time + 1 });
			Maze[nz][nx][ny] = false;
		}
	}
}

// 큐브의 각 층을 한번씩 돌리는 부분
void Rotate_Cube(int idx) {
	if (idx >= 5) {
		Exit_Cube();
		return;
	}

	bool temp[5][5];
	for (int i = 0; i < 4; i++) {
		for (int x = 0; x < 5; x++) {
			for (int y = 0; y < 5; y++)
				temp[x][y] = Cube[idx][y][4 - x];
		}

		for (int x = 0; x < 5; x++) {
			for (int y = 0; y < 5; y++) 
				Cube[idx][x][y] = temp[x][y];
		}

		Rotate_Cube(idx + 1);
	}
}

// 큐브의 각 층을 결정하는 부분
void Make_Cube(int idx) {
	if (idx >= 5) {
		Rotate_Cube(0);
		return;
	}

	for (int i = 0; i < 5; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		for (int x = 0; x < 5; x++) {
			for (int y = 0; y < 5; y++)
				Cube[idx][x][y] = Block[i][x][y];
		}
		Make_Cube(idx + 1);
		visited[i] = false;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// 5개의 판 입력
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) 
				cin >> Block[i][j][k];
		}
	}

	Make_Cube(0);

	if (Ans == INF) Ans = -1;
	cout << Ans;

	return 0;
}