#include <iostream>
#include <vector>
#define SIZE 105
using namespace std;

int N;
bool isCurve[SIZE][SIZE];

int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1, 0, -1, 0 };

// 드래곤 커브 방향 리스트
void Dragon_Curve(int depth, int generation, vector<int>& dir) {
	if (depth == generation) return;
	for (int i = dir.size() - 1; i >= 0; i--) dir.push_back((dir[i] + 1) % 4);
	Dragon_Curve(depth + 1, generation, dir);
}

// 드래곤 커브 그리기
void Draw_Curve(int x, int y, vector<int>& dir) {
	isCurve[x][y] = true;
	int nx = x, ny = y;
	for (int i : dir) {
		nx = nx + dx[i];
		ny = ny + dy[i];
		isCurve[nx][ny] = true;
	}
}

// 정사각형 개수 구하기
int Count_Square() {
	int result = 0;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (isCurve[i][j] && isCurve[i + 1][j] && isCurve[i][j + 1] && isCurve[i + 1][j + 1])
				result++;
		}
	}
	return result;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N;

	int x, y, d, g;
	for (int i = 0; i < N; i++) {
		cin >> x >> y >> d >> g;
		vector<int> dir(1, d);
		Dragon_Curve(0, g, dir);
		Draw_Curve(y, x, dir);
	}

	cout << Count_Square();

	return 0;
}