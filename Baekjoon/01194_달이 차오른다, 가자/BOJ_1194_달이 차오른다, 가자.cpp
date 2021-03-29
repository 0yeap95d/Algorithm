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
	
	// ���� N, ���� M
	cin >> N >> M;

	// �̷� �Է�, ���� ��ġ (x, y)
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

			// ����, �� �˻�
			if (nx < 0 || nx >= N || ny < 0 || ny >= M || maze[nx][ny] == '#') continue;

			// �湮 ���� �˻�
			if (visited[nx][ny][key[0]][key[1]][key[2]][key[3]][key[4]][key[5]]) continue;

			// �ⱸ�� �� ��� �� ����
			if (maze[nx][ny] == '1') {
				cout << time + 1;
				return 0;
			}

			// ���� �ִ� ĭ, Ű�� ���ٸ� �� �̻� ���ԺҰ�
			if (maze[nx][ny] >= 'A' && maze[nx][ny] <= 'F' && !key[maze[nx][ny] - 'A']) continue;

			// ���� �ִ� ĭ
			if (maze[nx][ny] >= 'a' && maze[nx][ny] <= 'f') key[maze[nx][ny] - 'a'] = true;

			// �湮 üũ
			visited[nx][ny][key[0]][key[1]][key[2]][key[3]][key[4]][key[5]] = true;
			
			que.push({ nx, ny, time + 1, key });
		}
	}

	// Ż���� �� ���� ��
	cout << -1;

	return 0;
}