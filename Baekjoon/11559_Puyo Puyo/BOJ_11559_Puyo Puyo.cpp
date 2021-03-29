#include <iostream>
#include <queue>
#include <cstring>
#define WIDTH 6
#define HEIGHT 12
using namespace std;

int ans;
char field[HEIGHT][WIDTH];
bool visited[HEIGHT][WIDTH];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

void dropPuyo() {
	for (int i = HEIGHT - 2; i >= 0; i--) {
		for (int j = 0; j < WIDTH; j++) {
			if (field[i][j] == '.') continue;
			
			// 뿌요 떨어뜨리기
			char color = field[i][j];
			int ni = i + 1;
			while (ni < HEIGHT && field[ni][j] == '.') ni++;
			field[i][j] = '.';
			field[ni - 1][j] = color;
		}
	}
}

bool boomPuyo(int x, int y) {

	vector<pair<int, int>> chain;
	queue<pair<int, int>> que;
	
	chain.push_back({ x, y });
	que.push({ x, y });
	visited[x][y] = true;

	// BFS를 이용해 뿌요 연결 확인
	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();

		for (int di = 0; di < 4; di++) {
			int nx = x + dx[di];
			int ny = y + dy[di];

			if (nx < 0 || nx >= HEIGHT || ny < 0 || ny >= WIDTH) continue;
			if (visited[nx][ny] || field[nx][ny] != field[x][y]) continue;

			chain.push_back({ nx, ny });
			que.push({ nx, ny });
			visited[nx][ny] = true;
		}
	}

	// 4개 이상 모여있지 않을 때 
	if (chain.size() < 4) return false;
	
	// 4개 이상 모여있을 때
	for (pair<int, int> pos : chain) 
		field[pos.first][pos.second] = '.';

	return true;
}

int main() {

	// 필트 정보 입력
	for (int i = 0; i < HEIGHT; i++) cin >> field[i];

	while (1) {
		memset(visited, false, sizeof(visited));
		bool isBoom = false;
		for (int i = 0; i < HEIGHT; i++) {
			for (int j = 0; j < WIDTH; j++) {
				if (field[i][j] == '.' || visited[i][j]) continue;
				if (boomPuyo(i, j)) isBoom = true;
			}
		}
		if (!isBoom) break;
		else ans++;

		dropPuyo();
	}

	// 정답 출력
	cout << ans;

	return 0;
}