#include <iostream>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;

struct Data {
	int x;
	int y;
	int time;
	vector<bool> key;
};

int maze[50][50];
int N, M;
bool visited[50][50][2][2][2][2][2][2];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
queue<Data> que;

int main() {

	ios_base::sync_with_stdio(false); 
	cin.tie(NULL), cout.tie(NULL); 
	
	// 세로 N, 가로 M
	cin >> N >> M;

	// 미로 입력, 현재 위치 (x, y)
	string inp;
	int x, y;
	for (int i = 0; i < N; i++) {
		cin >> inp;
		for (int j = 0; j < M; j++) {
			maze[i][j] = inp[j];
			if (maze[i][j] == '0') x = i, y = j;
		}
	}

	visited[x][y][0][0][0][0][0][0] = true;
	que.push({ x, y, 0, vector<bool>(6, false) });

	while (!que.empty()) {
		Data data = que.front();
		que.pop();

		for (int i = 0; i < 4; i++) {
			int nx = data.x + dx[i];
			int ny = data.y + dy[i];
			int time = data.time;
			vector<bool> key = data.key;

			// 범위, 벽 검사
			if (nx < 0 || nx >= N || ny < 0 || ny >= M || maze[nx][ny] == '#') continue;

			// 방문 유무 검사
			if (visited[nx][ny][key[0]][key[1]][key[2]][key[3]][key[4]][key[5]]) continue;

			// 출구일 때 출력 후 종료
			if (maze[nx][ny] == '1') {
				cout << time + 1;
				return 0;
			}

			// 문이 있는 칸, 키가 없다면 더 이상 진입불가
			if (maze[nx][ny] >= 'A' && maze[nx][ny] <= 'F' && !key[maze[nx][ny] - 'A']) continue;

			// 열쇠 있는 칸
			if (maze[nx][ny] >= 'a' && maze[nx][ny] <= 'f') key[maze[nx][ny] - 'a'] = true;

			// 방문 체크
			visited[nx][ny][key[0]][key[1]][key[2]][key[3]][key[4]][key[5]] = true;
			
			que.push({ nx, ny, time + 1, key });
		}
	}

	// 탈출할 수 없을 때
	cout << -1;

	return 0;
}