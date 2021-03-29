#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, ans[2];

void setBishop(int cnt, vector<vector<bool>> board, int color){

	// 놓을 수 있는 곳 찾기
	int x, y;
	x = y = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if ((i + j) % 2 == color && board[i][j] == true) {
				x = i, y = j;
				break;
			}
		}
		if (x != -1 && y != -1) break;
	}

	// 더 이상 놓을 수 있는 곳 없을 때
	if (x == -1 && y == -1) {
		ans[color] = max(ans[color], cnt);
		return;
	}

	// 비숍을 놓지 않았을 때
	board[x][y] = false;
	setBishop(cnt, board, color);

	// 비숍을 놓았을 때
	for (int i = 0; i < N; i++) {
		if (x + i < N && y + i < N) board[x + i][y + i] = false;
		if (x + i < N && y - i >= 0) board[x + i][y - i] = false;
		if (x - i >= 0 && y + i < 0) board[x - i][y + i] = false;
		if (x - i >= 0 && y - i >= 0) board[x - i][y - i] = false;
	}
	setBishop(cnt + 1, board, color);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// 체스판 크기 N 입력
	cin >> N;

	// 체스판 입력
	int num;
	vector<vector<bool>> inp(N, vector<bool>(N, false));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> num;
			inp[i][j] = num;
		}
	}

	// 백트레킹
	setBishop(0, inp, 0);
	setBishop(0, inp, 1);

	// 정답출력
	cout << ans[0] + ans[1];

	return 0;
}