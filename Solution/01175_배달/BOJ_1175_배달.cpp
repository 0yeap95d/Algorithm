#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

char room[50][50];
bool visited[50][50][4][2][2];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

struct Data {
	int x;
	int y;
	int dir;
	int time;
	bool visitedC; 
	bool visitedD;
};

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	string inp;
	int x, y;
	bool change = false;

	// 배열 입력, C 두개 중 하나를 D로 바꾼다
	for (int i = 0; i < N; i++) {
		cin >> inp;
		for (int j = 0; j < M; j++) {
			room[i][j] = inp[j];
			if (room[i][j] == 'S') x = i, y = j;
			if (room[i][j] == 'C' && !change) {
				room[i][j] = 'D';
				change = true;
			}
		}
	}


	queue<Data> que;
	que.push({ x, y, -1, 0, false, false});

	while (!que.empty()) {
		Data data = que.front();
		que.pop();

		for (int i = 0; i < 4; i++) {
			
			// 같은 방향 두 번 연속 이동불가
			if (data.dir == i) continue;

			// 다음 방향
			int nx = data.x + dx[i];
			int ny = data.y + dy[i];

			// 범위, 벽 체크
			if (nx < 0 || nx >= N || ny < 0 || ny >= M || room[nx][ny] == '#') continue;

			// 방문체크
			if (visited[nx][ny][i][data.visitedC][data.visitedD]) continue;
			

			bool visitedC = data.visitedC;
			bool visitedD = data.visitedD;

			if (room[nx][ny] == 'C') {
				// C, D 모두 방문했을 때
				if (visitedD) {
					cout << data.time + 1;
					return 0;
				}

				// C만 방문 했을 때
				visitedC = true;
			}
			else if (room[nx][ny] == 'D') {
				// C, D 모두 방문했을 때
				if (visitedC) {
					cout << data.time + 1;
					return 0;
				}
				// D만 방문 했을 때
				visitedD = true;
			}


			visited[nx][ny][i][visitedC][visitedD] = true;
			que.push({ nx, ny, i, data.time + 1, visitedC, visitedD });
		}
	}

	// 불가능 할 때
	cout << -1;

	return 0;
}