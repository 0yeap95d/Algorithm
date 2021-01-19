#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#define SIZE 101
using namespace std;

struct Snake {
	int x;
	int y;
	int dir;
};

int N, K, L;
bool isSnake[SIZE][SIZE], isApple[SIZE][SIZE];
queue<pair<int, char>> command;
deque<Snake> snake;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

// 방향 전환
int Change_Dir(char com, int dir) {
	// 왼쪽으로 90도 회전
	if (com == 'L') return (dir + 3) % 4;

	// 오른쪽으로 90도 회전
	else return (dir + 1) % 4;
}

// 뱀 이동
int Move_Snake() {
	int time = 0;
	snake.push_back({ 0, 0, 3 });
	isSnake[0][0] = true;

	while (++time) {
		int di = snake.front().dir;
		int nx = snake.front().x + dx[di];
		int ny = snake.front().y + dy[di];

		// 벽 또는 자기자신의 몸과 부딪히면 게임 끝
		if (nx < 0 || nx >= N || ny < 0 || ny >= N || isSnake[nx][ny]) break;

		// 머리를 다음칸에 위치
		isSnake[nx][ny] = true;
		snake.push_front({ nx, ny, di });
		

		// 사과가 있다면 꼬리 움직이지 않음
		if (isApple[nx][ny]) isApple[nx][ny] = false;

		// 사과가 없다면 꼬리 움직임
		else {
			isSnake[snake.back().x][snake.back().y] = false;
			snake.pop_back();
		}

		// X초가 끝난 뒤에 방향 전환
		if (!command.empty() && time == command.front().first) {
			snake.front().dir = Change_Dir(command.front().second, snake.front().dir);
			command.pop();
		}
	}

	return time;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> K;
	int r, c;
	for (int i = 0; i < K; i++) {
		cin >> r >> c;
		isApple[r - 1][c - 1] = true;
	}

	cin >> L;
	int time;
	char com;
	for (int i = 0; i < L; i++) {
		cin >> time >> com;
		command.push({ time, com });
	}

	cout << Move_Snake();

	return 0;
}