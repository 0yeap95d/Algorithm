#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, ans[2];

void setBishop(int cnt, vector<vector<bool>> board, int color){

	// ���� �� �ִ� �� ã��
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

	// �� �̻� ���� �� �ִ� �� ���� ��
	if (x == -1 && y == -1) {
		ans[color] = max(ans[color], cnt);
		return;
	}

	// ����� ���� �ʾ��� ��
	board[x][y] = false;
	setBishop(cnt, board, color);

	// ����� ������ ��
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

	// ü���� ũ�� N �Է�
	cin >> N;

	// ü���� �Է�
	int num;
	vector<vector<bool>> inp(N, vector<bool>(N, false));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> num;
			inp[i][j] = num;
		}
	}

	// ��Ʈ��ŷ
	setBishop(0, inp, 0);
	setBishop(0, inp, 1);

	// �������
	cout << ans[0] + ans[1];

	return 0;
}