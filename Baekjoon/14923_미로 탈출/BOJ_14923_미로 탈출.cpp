#include <iostream>
#include <queue>
#define MAX 1001
using namespace std;

const int dx[4] = { 0, 0, -1, 1 };
const int dy[4] = { -1, 1, 0, 0 };

int N, M;
int Hx, Hy, Ex, Ey;
int Maze[MAX][MAX];
bool visited[MAX][MAX][2];

struct Position {
	int x;
	int y;
	int cnt;
	int wall;

	Position(int x, int y, int cnt, int wall)
		: x(x), y(y), cnt(cnt), wall(wall) {}
};

void init() {
	cin >> N >> M;
	cin >> Hx >> Hy >> Ex >> Ey;
	Hx--; Hy--; Ex--; Ey--;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> Maze[i][j];
		}
	}
}

bool isPossible(Position pos) {
	return 
		pos.x >= 0 && pos.x < N &&	// x 범위 체크
		pos.y >= 0 && pos.y < M &&	// y 범위 체크
		!visited[pos.x][pos.y][pos.wall] && // 방문 체크
		pos.wall < 2;	// 벽 체크
}

int bfs() {
	queue<Position> que;
	que.push(Position(Hx, Hy, 0, 0));

	while (!que.empty()) {
		Position pos = que.front();
		que.pop();

		for (int i = 0; i < 4; i++) {
			int nx = pos.x + dx[i];
			int ny = pos.y + dy[i];
			int nCnt = pos.cnt + 1;
			int nWall = pos.wall + Maze[nx][ny];
			Position nextPos(nx, ny, nCnt, nWall);
			if (!isPossible(nextPos)) continue;
			if (nx == Ex && ny == Ey) return pos.cnt + 1;
			visited[nx][ny][nWall] = true;
			que.push(nextPos);
		}
	}

	return -1;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	init();
	cout << bfs();

	return 0;
}