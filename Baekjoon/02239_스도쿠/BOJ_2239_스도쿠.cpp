#include <iostream>
#include <cstring>
#include <vector>
#define SIZE 9
using namespace std;

vector<vector<int>> sudoku(SIZE, vector<int>(SIZE, 0));

// 백트레킹
bool backTracking(vector<vector<int>> board) {

	// 빈 칸 찾기
	int nx, ny;
	nx = ny = -1;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (board[i][j] == 0) {
				nx = i;
				ny = j;
				break;
			}
		}
		if (nx != -1 || ny != -1) break;
	}

	// 더 이상 빈 칸이 없을 때
	if (nx == -1 || ny == -1) {
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) cout << board[i][j];
			cout << "\n";
		}
		return true;
	}

	// 사용 가능한 숫자 체크
	bool visited[SIZE + 1] = { false, };
	for (int i = 0; i < SIZE; i++) {
		if (board[nx][i] != 0) visited[board[nx][i]] = true;
		if (board[i][ny] != 0) visited[board[i][ny]] = true;
	}
	for (int i = (nx / 3) * 3; i < (nx / 3 + 1) * 3; i++) {
		for (int j = (ny / 3) * 3; j < (ny / 3 + 1) * 3; j++) {
			if (board[i][j] != 0) visited[board[i][j]] = true;
		}
	}

	// 빈 칸에 들어갈 수 있는 숫자
	bool isSuccess = false;
	for (int i = 1; i <= SIZE; i++) {
		if (visited[i]) continue;
		isSuccess = true;
		board[nx][ny] = i;
		if (backTracking(board)) return true;
	}

	if (!isSuccess) return false;
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// 스도쿠 입력
	string inp;
	for (int i = 0; i < SIZE; i++) {
		cin >> inp;
		for (int j = 0; j < SIZE; j++) {
			sudoku[i][j] = inp[j] - '0';
		}
	}

	// 백트래킹
	backTracking(sudoku);

	return 0;
}