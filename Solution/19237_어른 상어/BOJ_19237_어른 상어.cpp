#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Shark {
	int n;
	int x;
	int y;
	int time;
	int dir;
};

int N, M, k;
vector<vector<Shark>> grid;
map<int, Shark> pos;
int priorityDir[401][5][5];
vector<Shark> nextPos;

int dx[5] = { 0, -1, 1, 0, 0 };
int dy[5] = { 0, 0, 0, -1, 1 };

bool nextShark(int n, int findNum) {
	Shark shark = pos[n];

	// ����� ��ǥ�� (0, 0)�̶�� ���� ���
	if (shark.n == 0) return true;

	bool isMove = false;
	for (int di = 1; di <= 4; di++) {
		// ��� ������ ��ġ ����
		int idx = priorityDir[n][shark.dir][di];
		int nx = shark.x + dx[idx];
		int ny = shark.y + dy[idx];

		// ���� ���� üũ
		if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

		// ���� üũ
		if (grid[nx][ny].n != findNum) continue;

		// �̵� ����
		isMove = true;

		// ������ ��ġ ����
		nextPos.push_back({ n, nx, ny, k, idx });
		break;
	}

	return isMove;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	// ����ũ�� N, ����� �� M, �ð� k
	cin >> N >> M >> k;
	grid.assign(N, vector<Shark>(N, Shark()));
	

	// ��� �Է�
	int num;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> num;
			if (num == 0) continue;
			grid[i][j] = { num, i, j, k, 0 };
			pos[num] = { num, i, j, k, 0 };
		}
	}
	
	// ��� ���� �Է�
	int dir;
	for (int i = 1; i <= M; i++) {
		cin >> dir;
		pos[i].dir = dir;
		grid[pos[i].x][pos[i].y].dir = dir;
	}

	// ��� ���� �켱���� �Է�
	for (int i = 1; i <= M; i++) {
		for (int a = 1; a <= 4; a++) {
			for (int b = 1; b <= 4; b++) {
				cin >> priorityDir[i][a][b];
			}
		}
	}

	
	int ans, curTime, cntShark;
	ans = curTime = 0;
	cntShark = M;
	while (curTime < 1000 && cntShark > 1) {
		nextPos.clear();
		curTime++;

		// ��� ������ ��ġ ����
		for (int i = 1; i <= M; i++) {
			if (nextShark(i, 0)) continue;
			nextShark(i, i);
		}

		// ���� �����ִ� �ð� -1
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (grid[i][j].n == 0) continue;
				grid[i][j].time--;
				if (grid[i][j].time != 0) continue;
				grid[i][j] = { 0, 0, 0, 0, 0 };
			}
		}

		// ��� �̵�
		for (int i = 0; i < nextPos.size(); i++) {
			Shark shark = nextPos[i];
			
			// �̵��� ��ġ�� �� ĭ�̰ų� �ڽ��� ������ ������ ��
			if (grid[shark.x][shark.y].n == 0 || grid[shark.x][shark.y].n == shark.n) {
				grid[shark.x][shark.y] = pos[shark.n] = shark;
			}

			// �̵��� ��ġ�� �����ϴ� �� �ڱ⺸�� ���� ��
			else if (grid[shark.x][shark.y].n < shark.n) {
				cntShark--;
				pos[shark.n] = { 0, 0, 0, 0, 0 };
			}

			// �̵��� ��ġ�� �����ϴ� �� �ڱ⺸�� Ŭ ��
			else if (grid[shark.x][shark.y].n < shark.n) {
				cntShark--;
				pos[grid[shark.x][shark.y].n] = { 0, 0, 0, 0, 0 };
				grid[shark.x][shark.y] = pos[shark.n] = shark;
			}
		}
	}

	// ���� ���
	if (cntShark == 1) ans = curTime;
	else ans = -1;
	cout << ans;

	return 0;
}