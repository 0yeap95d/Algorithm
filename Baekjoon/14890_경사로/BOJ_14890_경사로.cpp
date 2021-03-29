#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int N, L, ans;
vector<vector<int>> map;
vector<vector<bool>> visitedRow;
vector<vector<bool>> visitedCol;


// dir�� 0 �̸� ������, 1�̸� ������
bool rowCheck(int x, int y, int dir) {
	
	// ���� ��ġ�� ����
	int start, end;
	if (dir == 0) start = y - L + 1, end = y;
	else start = y + 1, end = y + L;

	// ��ġ ������ ������ ����� false�� return
	if (start < 0 || start >= N || end < 0 || end >= N) return false;
	
	// ���̰� �������� �ʰų� �湮üũ�� �Ǿ������� false�� return
	int height = map[x][start];
	for (int i = start; i <= end; i++) {
		if (height != map[x][i] || visitedRow[x][i]) return false;
	}

	// ��� �����ϸ� �湮 üũ �� true�� return
	for (int i = start; i <= end; i++) visitedRow[x][i] = true;
	return true;
}

bool colCheck(int x, int y, int dir) {

	// ���� ��ġ�� ����
	int start, end;
	if (dir == 0) start = x - L + 1, end = x;
	else start = x + 1, end = x + L;

	// ��ġ ������ ������ ����� false�� return
	if (start < 0 || start >= N || end < 0 || end >= N) return false;

	// ���̰� �������� �ʰų� �湮üũ�� �Ǿ������� false�� return
	int height = map[start][y];
	for (int i = start; i <= end; i++) {
		if (height != map[i][y] || visitedCol[i][y]) return false;
	}

	// ��� �����ϸ� �湮 üũ �� true�� return
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

	// ���� �Է�
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	// ���� ���� ����
	for (int i = 0; i < N; i++) {
		bool isSuccess = true;
		for (int j = 0; j < N - 1; j++) {
			if (abs(map[i][j] - map[i][j + 1]) > 1) { isSuccess = false; break; }
			else if (map[i][j] < map[i][j + 1] && !rowCheck(i, j, 0)) { isSuccess = false; break; }
			else if (map[i][j] > map[i][j + 1] && !rowCheck(i, j, 1)) { isSuccess = false; break; }
		}
		if (isSuccess) ans++;
	}

	// ���� ���� ����
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