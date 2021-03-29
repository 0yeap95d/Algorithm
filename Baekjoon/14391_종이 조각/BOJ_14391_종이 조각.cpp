#include <iostream>
#include <cstring>
#include <algorithm>
#define SIZE 4
using namespace std;

int N, M;
int Paper[SIZE][SIZE];

int Divide_Paper(int sx, int sy, int ex, int ey) {

	// 가로로 자르기
	int row_result = 0;
	if (sx == ex) {
		for (int i = sy; i <= ey; i++) {
			row_result = row_result * 10;
			row_result = row_result + Paper[sx][i];
		}
	}
	else {
		for (int i = sx; i < ex; i++) 
			row_result = max(row_result, Divide_Paper(sx, sy, i, ey) + Divide_Paper(i + 1, sy, ex, ey));
	}

	// 세로로 자르기
	int col_result = 0;
	if (sy == ey) {
		for (int i = sx; i <= ex; i++) {
			col_result = col_result * 10;
			col_result = col_result + Paper[i][sy];
		}
	}
	else {
		for (int i = sy; i < ey; i++) 
			col_result = max(col_result, Divide_Paper(sx, sy, ex, i) + Divide_Paper(sx, i + 1, ex, ey));
	}

	return max(row_result, col_result);
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// 입력
	string inp;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> inp;
		for (int j = 0; j < M; j++) Paper[i][j] = inp[j] - '0';
	}

	// 출력
	cout << Divide_Paper(0, 0, N - 1, M - 1);

	return 0;
}