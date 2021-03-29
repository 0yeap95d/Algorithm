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

	// �迭 �Է�, C �ΰ� �� �ϳ��� D�� �ٲ۴�
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
			
			// ���� ���� �� �� ���� �̵��Ұ�
			if (data.dir == i) continue;

			// ���� ����
			int nx = data.x + dx[i];
			int ny = data.y + dy[i];

			// ����, �� üũ
			if (nx < 0 || nx >= N || ny < 0 || ny >= M || room[nx][ny] == '#') continue;

			// �湮üũ
			if (visited[nx][ny][i][data.visitedC][data.visitedD]) continue;
			

			bool visitedC = data.visitedC;
			bool visitedD = data.visitedD;

			if (room[nx][ny] == 'C') {
				// C, D ��� �湮���� ��
				if (visitedD) {
					cout << data.time + 1;
					return 0;
				}

				// C�� �湮 ���� ��
				visitedC = true;
			}
			else if (room[nx][ny] == 'D') {
				// C, D ��� �湮���� ��
				if (visitedC) {
					cout << data.time + 1;
					return 0;
				}
				// D�� �湮 ���� ��
				visitedD = true;
			}


			visited[nx][ny][i][visitedC][visitedD] = true;
			que.push({ nx, ny, i, data.time + 1, visitedC, visitedD });
		}
	}

	// �Ұ��� �� ��
	cout << -1;

	return 0;
}