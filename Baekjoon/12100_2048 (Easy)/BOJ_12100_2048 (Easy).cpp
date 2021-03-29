#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, ans;
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };

vector<vector<int>> board;

// ���忡�� ���� ū ���� ����
int getMaxValue(vector<vector<int>> &block) {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) 
			ret = max(ret, block[i][j]);
	}
	return ret;
}

// ��� �̵�
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

			// ���� ���� ����̸� ����
			if (block[i][j] == 0) {
				if (dir < 2) j++;
				else j--;
				continue;
			}

			// ���� ��ġ
			int cx = i, cy = j;

			while (1) {
				// �̵��ؾ� �� ��ǥ ����
				int nx = cx + dx[dir];
				int ny = cy + dy[dir];

				// ���� üũ
				if (nx < 0 || nx >= N || ny < 0 || ny >= N) break;

				// ����ĭ�� �̵� �����ϴٸ� (��ĭ�� ��)
				if (block[nx][ny] == 0) {
					isMove = true;
					block[nx][ny] = block[cx][cy];
					block[cx][cy] = 0;
					cx = nx;
					cy = ny;
				}

				// ��ĥ �� �ִ� ĭ�̶��, �湮üũ �� ��ħ
				else if (block[nx][ny] == block[cx][cy] && !visited[nx][ny]) {
					isMove = true;
					visited[nx][ny] = true;
					block[nx][ny] = block[nx][ny] + block[cx][cy];
					block[cx][cy] = 0;
					break;
				}

				// �� �̻� �̵��Ұ�
				else break;

			}
			if (dir < 2) j++;
			else j--;
		}
		if (dir < 2) i++;
		else i--;
	}

	// �ѹ��̶� ����� �̵��ߴٸ� true, �ƴϸ� false
	return isMove;
}

// ����Ž��
void startGame(int idx , vector<vector<int>> block, vector<int> order) {
	if (idx >= 5) {
		// ans�� �ִ밪���� ����
		ans = max(ans, getMaxValue(block));
		return;
	}

	for (int i = 0; i < 4; i++) {
		vector<vector<int>> temp(block.begin(), block.end());
		if (!moveBlock(i, temp)) continue;	// ������ �� �ִ°� ���ٸ� ����
		order[idx] = i;
		startGame(idx + 1, temp, order);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// ������ ũ��
	cin >> N;
	board.assign(N, vector<int>(N, 0));

	// ���� �� �Է�
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) 
			cin >> board[i][j];
	}

	ans = getMaxValue(board);
	startGame(0, board, vector<int>(6, 0));
	cout << ans;

	return 0;
}