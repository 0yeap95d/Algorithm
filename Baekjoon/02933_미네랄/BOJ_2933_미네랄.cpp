#include <iostream>
#include <cstring>
#include <queue>
#define SIZE 101
using namespace std;

int R, C, N;
string Cave[101];
bool visited[SIZE][SIZE];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

void deleteMineral(int height, int dir) {
	int r = R - height;

	// 왼쪽에서 던질 때
	if (dir == 0) {
		for (int c = 0; c < C; c++) {
			if (Cave[r][c] == '.') continue;
			Cave[r][c] = '.';
			break;
		}
	}

	// 오른쪽에서 던질 때
	else {
		for (int c = C - 1; c >= 0; c--) {
			if (Cave[r][c] == '.') continue;
			Cave[r][c] = '.';
			break;
		}
	}
}

// 바닥과 붙어있는 미네랄 체크
void fixMineral() {
	int r = R - 1;
	queue<pair<int, int>> que;
	
	for (int c = 0; c < C; c++) {
		if (visited[r][c] || Cave[r][c] == '.') continue;
		
		que.push({ r, c });
		visited[r][c] = true;
		while (!que.empty()) {
			int x = que.front().first;
			int y = que.front().second;
			que.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
				if (visited[nx][ny] || Cave[nx][ny] == '.') continue;

				que.push({ nx, ny });
				visited[nx][ny] = true;
			}
		}
	}
}

void dropMineral() {
	queue<pair<int, int>> que, temp;

	for (int r = R - 1; r >= 0; r--) {
		for (int c = 0; c < C; c++) {
			if (Cave[r][c] == '.' || visited[r][c]) continue;
			que.push({ r, c });
		}
	}

	while (!que.empty()) {
		while (!que.empty()) {
			int r = que.front().first;
			int c = que.front().second;
			que.pop();

			if (r + 1 >= R || visited[r + 1][c]) return;
			temp.push({ r, c });
		}

		while (!temp.empty()) {
			int r = temp.front().first;
			int c = temp.front().second;
			temp.pop();

			Cave[r][c] = '.';
			Cave[r + 1][c] = 'x';
			que.push({ r + 1, c });
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// 동굴 정보 입력
	cin >> R >> C;
	for (int i = 0; i < R; i++) cin >> Cave[i];
	
	cin >> N;
	int height;
	for (int i = 0; i < N; i++) {
		cin >> height;
		memset(visited, 0, sizeof(visited));
		
		deleteMineral(height, i % 2);
		fixMineral();
		dropMineral();
	}
	for (int r = 0; r < R; r++) cout << Cave[r] << "\n";


	return 0;
}