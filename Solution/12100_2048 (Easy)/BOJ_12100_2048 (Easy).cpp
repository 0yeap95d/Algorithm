#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, ans;
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };

vector<vector<int>> board;

// 보드에서 제일 큰 값을 리턴
int getMaxValue(vector<vector<int>> &block) {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) 
			ret = max(ret, block[i][j]);
	}
	return ret;
}

// 블록 이동
bool moveBlock(int dir, vector<vector<int>> &block) {
	bool isMove = false;
	vector<vector<bool>> visited(N, vector<bool>(N, false));
	int i, j;

	if (dir < 2) i = 0;
	else i = N - 1;

	while (i < N && i >= 0) {
		if (dir < 2) j = 0;
		else j = N - 1;
		while (j < N && j >= 0) {

			// 값이 없는 블록이면 다음
			if (block[i][j] == 0) {
				if (dir < 2) j++;
				else j--;
				continue;
			}

			// 현재 위치
			int cx = i, cy = j;

			while (1) {
				// 이동해야 할 좌표 설정
				int nx = cx + dx[dir];
				int ny = cy + dy[dir];

				// 범위 체크
				if (nx < 0 || nx >= N || ny < 0 || ny >= N) break;

				// 다음칸이 이동 가능하다면 (빈칸일 때)
				if (block[nx][ny] == 0) {
					isMove = true;
					block[nx][ny] = block[cx][cy];
					block[cx][cy] = 0;
					cx = nx;
					cy = ny;
				}

				// 합칠 수 있는 칸이라면, 방문체크 후 합침
				else if (block[nx][ny] == block[cx][cy] && !visited[nx][ny]) {
					isMove = true;
					visited[nx][ny] = true;
					block[nx][ny] = block[nx][ny] + block[cx][cy];
					block[cx][cy] = 0;
					break;
				}

				// 더 이상 이동불가
				else break;

			}
			if (dir < 2) j++;
			else j--;
		}
		if (dir < 2) i++;
		else i--;
	}

	// 한번이라도 블록이 이동했다면 true, 아니면 false
	return isMove;
}

// 완전탐색
void startGame(int idx , vector<vector<int>> block, vector<int> order) {
	if (idx >= 5) {
		// ans를 최대값으로 갱신
		ans = max(ans, getMaxValue(block));
		return;
	}

	for (int i = 0; i < 4; i++) {
		vector<vector<int>> temp(block.begin(), block.end());
		if (!moveBlock(i, temp)) continue;	// 움직일 수 있는게 없다면 다음
		order[idx] = i;
		startGame(idx + 1, temp, order);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 보드의 크기
	cin >> N;
	board.assign(N, vector<int>(N, 0));

	// 보드 값 입력
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) 
			cin >> board[i][j];
	}

	ans = getMaxValue(board);
	startGame(0, board, vector<int>(6, 0));
	cout << ans;

	return 0;
}