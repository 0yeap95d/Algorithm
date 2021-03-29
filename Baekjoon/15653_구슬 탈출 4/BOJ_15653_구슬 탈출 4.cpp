#include <iostream>
#include <queue>
#define SIZE 15
using namespace std;

struct State {
	int rx;
	int ry;
	int bx;
	int by;
	int time;
};

int N, M, Answer = -1;
char Board[SIZE][SIZE];
bool visited[SIZE][SIZE][SIZE][SIZE];
queue<State> que;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

// 게임판 기울이기
State moveBoard(State state, int dir) {

	State res = state;
	res.time++;
	int x, y;

	Board[res.rx][res.ry] = 'R';
	Board[res.bx][res.by] = 'B';


	// 빨간 구슬 이동
	x = res.rx, y = res.ry;
	while (true) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (Board[nx][ny] != '.') {
			if (Board[nx][ny] == 'O') {
				Board[x][y] = '.';
				x = y = -1;
			}
			break;
		}
		Board[nx][ny] = 'R';
		Board[x][y] = '.';
		x = nx, y = ny;
	}
	res.rx = x, res.ry = y;


	// 파란 구슬 이동
	x = res.bx, y = res.by;
	while (true) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (Board[nx][ny] != '.') {
			if (Board[nx][ny] == 'O') {
				Board[x][y] = '.';
				x = y = -1;
			}
			break;
		}
		Board[nx][ny] = 'B';
		Board[x][y] = '.';
		x = nx, y = ny;
	}
	res.bx = x, res.by = y;


	x = res.rx, y = res.ry;
	if (x == -1 && y == -1) return res;

	while (true) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (Board[nx][ny] != '.') {
			if (Board[nx][ny] == 'O') {
				Board[x][y] = '.';
				x = y = -1;
			}
			break;
		}
		Board[nx][ny] = 'R';
		Board[x][y] = '.';
		x = nx, y = ny;
	}
	res.rx = x, res.ry = y;

	Board[res.rx][res.ry] = Board[res.bx][res.by] = '.';
	return res;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	State state;
	pair<int, int> hole;

	// 입력
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> Board[i][j];
			if (Board[i][j] == 'R') {
				Board[i][j] = '.';
				state.rx = i;
				state.ry = j;
			}
			else if (Board[i][j] == 'B') {
				Board[i][j] = '.';
				state.bx = i;
				state.by = j;
			}
			else if (Board[i][j] == 'O') {
				hole.first = i;
				hole.second = j;
			}
		}
	}

	// BFS
	state.time = 0;
	que.push(state);
	visited[state.rx][state.ry][state.bx][state.by] = true;
	while (!que.empty()) {
		State s = que.front();
		que.pop();

		bool isEnd = false;
		for (int i = 0; i < 4; i++) {
			State temp = moveBoard(s, i);

			if (temp.rx == -1) {
				if (temp.bx == -1) continue;
				else Answer = temp.time;
				isEnd = true;
				break;
			}

			else if (temp.bx == -1) continue;

			// 중복 체크
			if (visited[temp.rx][temp.ry][temp.bx][temp.by]) continue;

			// 삽입
			que.push(temp);
			visited[temp.rx][temp.ry][temp.bx][temp.by] = true;
		}
		if (isEnd) break;
	}

	cout << Answer;

	return 0;
}