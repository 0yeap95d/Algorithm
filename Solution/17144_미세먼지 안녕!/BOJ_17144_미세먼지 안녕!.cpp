#include <iostream>
#include <vector>

#define SIZE 51

using namespace std;

struct MicroDust {
	int x;
	int y;
	int weight;
};

int R, C, T;
int map[SIZE][SIZE];
pair<int, int> upPos, downPos;

int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1, 0, -1, 0 };

bool isInRange(int x, int y) {
	return !(x < 0 || x >= R || y < 0 || y >= C);
}

// 미세먼지 확산
void Spread_Dust() {

	vector<MicroDust> microDusts;

	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			if (map[r][c] <= 0) continue;

			int cnt = 0;
			int weight = map[r][c] / 5;
			for (int di = 0; di < 4; di++) {
				int nx = r + dx[di];
				int ny = c + dy[di];

				// 범위, 공기청정기 위치 체크
				if (!isInRange(nx, ny) || map[nx][ny] == -1) continue;

				cnt++;
				microDusts.push_back({ nx, ny, weight });
			}

			// 남은 미세먼지
			microDusts.push_back({ r, c, map[r][c] - (weight * cnt) });
			map[r][c] = 0;
		}
	}

	for (MicroDust dust : microDusts) map[dust.x][dust.y] = map[dust.x][dust.y] + dust.weight;
}


// 위쪽 반시계방향 순환
void upCycle() {
	int x = upPos.first - 1;
	int y = upPos.second;
	
	for (int di = 3; di >= 0; di--) {
		int nx = x - dx[di];
		int ny = y - dy[di];
		while (isInRange(nx, ny) && nx <= upPos.first) {
			map[x][y] = map[nx][ny];
			x = nx; y = ny;
			nx = nx - dx[di];
			ny = ny - dy[di];
			if (map[nx][ny] == -1) {
				map[x][y] = 0;
				break;
			}
		}
	}
}

// 아래쪽 시계방향 순환
void downCycle() {
	int x = downPos.first + 1;
	int y = downPos.second;

	for (int di = 3; di >= 0; di--) {
		int nx = x + dx[di];
		int ny = y - dy[di];
		while (isInRange(nx, ny) && nx >= downPos.first) {
			map[x][y] = map[nx][ny];
			x = nx; y = ny;
			nx = nx + dx[di];
			ny = ny - dy[di];
			if (map[nx][ny] == -1) {
				map[x][y] = 0;
				break;
			}
		}
	}
}

// 공기청정기 작동
void Active_Aircleaner() {
	upCycle();
	downCycle();
}

// 남아있는 모든 미세먼지의 양
int getSumDust() {
	int result = 0;
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			if (map[r][c] <= 0) continue;
			result = result + map[r][c];
		}
	}
	return result;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> R >> C >> T;

	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			cin >> map[r][c];
			
			// 공기청정기 위치 저장
			if (map[r][c] == -1) {
				if (upPos.first == 0) upPos = { r, c };
				else downPos = { r, c };
			}
		}
	}

	while (T--) {
		Spread_Dust();
		Active_Aircleaner();
	}

	cout << getSumDust();

	return 0;
}