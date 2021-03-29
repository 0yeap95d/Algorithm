#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int N, L, ans;
vector<vector<int>> map;
vector<vector<bool>> visitedRow;
vector<vector<bool>> visitedCol;


// dir이 0 이면 오르막, 1이면 내리막
bool rowCheck(int x, int y, int dir) {
	
	// 경사로 설치할 범위
	int start, end;
	if (dir == 0) start = y - L + 1, end = y;
	else start = y + 1, end = y + L;

	// 설치 범위가 지도를 벗어나면 false를 return
	if (start < 0 || start >= N || end < 0 || end >= N) return false;
	
	// 높이가 일정하지 않거나 방문체크가 되어있으면 false를 return
	int height = map[x][start];
	for (int i = start; i <= end; i++) {
		if (height != map[x][i] || visitedRow[x][i]) return false;
	}

	// 모두 만족하면 방문 체크 후 true를 return
	for (int i = start; i <= end; i++) visitedRow[x][i] = true;
	return true;
}

bool colCheck(int x, int y, int dir) {

	// 경사로 설치할 범위
	int start, end;
	if (dir == 0) start = x - L + 1, end = x;
	else start = x + 1, end = x + L;

	// 설치 범위가 지도를 벗어나면 false를 return
	if (start < 0 || start >= N || end < 0 || end >= N) return false;

	// 높이가 일정하지 않거나 방문체크가 되어있으면 false를 return
	int height = map[start][y];
	for (int i = start; i <= end; i++) {
		if (height != map[i][y] || visitedCol[i][y]) return false;
	}

	// 모두 만족하면 방문 체크 후 true를 return
	for (int i = start; i <= end; i++) visitedCol[i][y] = true;
	return true;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	
	cin >> N >> L;
	map.assign(N, vector<int>(N, 0));
	visitedRow.assign(N, vector<bool>(N, false));
	visitedCol.assign(N, vector<bool>(N, false));

	// 지도 입력
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	// 가로 경사로 놓기
	for (int i = 0; i < N; i++) {
		bool isSuccess = true;
		for (int j = 0; j < N - 1; j++) {
			if (abs(map[i][j] - map[i][j + 1]) > 1) { isSuccess = false; break; }
			else if (map[i][j] < map[i][j + 1] && !rowCheck(i, j, 0)) { isSuccess = false; break; }
			else if (map[i][j] > map[i][j + 1] && !rowCheck(i, j, 1)) { isSuccess = false; break; }
		}
		if (isSuccess) ans++;
	}

	// 세로 경사로 놓기
	for (int j = 0; j < N; j++) {
		bool isSuccess = true;
		for (int i = 0; i < N - 1; i++) {
			if (abs(map[i][j] - map[i + 1][j]) > 1) { isSuccess = false; break; }
			else if (map[i][j] < map[i + 1][j] && !colCheck(i, j, 0)) { isSuccess = false; break; }
			else if (map[i][j] > map[i + 1][j] && !colCheck(i, j, 1)) { isSuccess = false; break; }
		}
		if (isSuccess) ans++;
	}

	cout << ans;

	return 0;
}