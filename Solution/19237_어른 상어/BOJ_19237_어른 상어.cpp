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

	// 상어의 좌표가 (0, 0)이라면 없는 상어
	if (shark.n == 0) return true;

	bool isMove = false;
	for (int di = 1; di <= 4; di++) {
		// 상어 움직일 위치 지정
		int idx = priorityDir[n][shark.dir][di];
		int nx = shark.x + dx[idx];
		int ny = shark.y + dy[idx];

		// 격자 범위 체크
		if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

		// 냄새 체크
		if (grid[nx][ny].n != findNum) continue;

		// 이동 가능
		isMove = true;

		// 움직일 위치 저장
		nextPos.push_back({ n, nx, ny, k, idx });
		break;
	}

	return isMove;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	// 격자크기 N, 상어의 수 M, 시간 k
	cin >> N >> M >> k;
	grid.assign(N, vector<Shark>(N, Shark()));
	

	// 상어 입력
	int num;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> num;
			if (num == 0) continue;
			grid[i][j] = { num, i, j, k, 0 };
			pos[num] = { num, i, j, k, 0 };
		}
	}
	
	// 상어 방향 입력
	int dir;
	for (int i = 1; i <= M; i++) {
		cin >> dir;
		pos[i].dir = dir;
		grid[pos[i].x][pos[i].y].dir = dir;
	}

	// 상어 방향 우선순위 입력
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

		// 상어 움직일 위치 저장
		for (int i = 1; i <= M; i++) {
			if (nextShark(i, 0)) continue;
			nextShark(i, i);
		}

		// 냄새 남아있는 시간 -1
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (grid[i][j].n == 0) continue;
				grid[i][j].time--;
				if (grid[i][j].time != 0) continue;
				grid[i][j] = { 0, 0, 0, 0, 0 };
			}
		}

		// 상어 이동
		for (int i = 0; i < nextPos.size(); i++) {
			Shark shark = nextPos[i];
			
			// 이동할 위치가 빈 칸이거나 자신의 냄새가 존재할 때
			if (grid[shark.x][shark.y].n == 0 || grid[shark.x][shark.y].n == shark.n) {
				grid[shark.x][shark.y] = pos[shark.n] = shark;
			}

			// 이동할 위치에 존재하는 상어가 자기보다 작을 때
			else if (grid[shark.x][shark.y].n < shark.n) {
				cntShark--;
				pos[shark.n] = { 0, 0, 0, 0, 0 };
			}

			// 이동할 위치에 존재하는 상어가 자기보다 클 때
			else if (grid[shark.x][shark.y].n < shark.n) {
				cntShark--;
				pos[grid[shark.x][shark.y].n] = { 0, 0, 0, 0, 0 };
				grid[shark.x][shark.y] = pos[shark.n] = shark;
			}
		}
	}

	// 정답 출력
	if (cntShark == 1) ans = curTime;
	else ans = -1;
	cout << ans;

	return 0;
}