#include <iostream>
using namespace std;

int Ans;
bool Green[6][4], Blue[6][4];

void transPos(int* t, int* x, int* y) {
	int tx = *x;
	int ty = *y;

	*x = ty, *y = 3 - tx;
	
	if (*t == 2) *t = 3;
	else if (*t == 3) {
		*t = 2;
		*y = *y - 1;
	}
}

void setBlock(bool board[][4], int t, int x, int y) {
	if (t == 2) {
		board[1][y] = board[1][y + 1] = true;
		for (int i = 2; i < 6; i++) {
			if (board[i][y] || board[i][y + 1]) break;
			else {
				board[i - 1][y] = board[i - 1][y + 1] = false;
				board[i][y] = board[i][y + 1] = true;
			}
		}
	}

	else {
		int pos = 1;
		board[1][y] = true;
		for (int i = 2; i < 6; i++) {
			if (board[i][y]) break;
			else {
				board[i - 1][y] = false;
				board[i][y] = true;
				pos = i;
			}
		}
		if (t == 3) board[pos - 1][y] = true;
	}
}

int checkRow(bool board[][4]) {

	for (int i = 5; i >= 2; i--) {
		bool isFull = true;
		for (int j = 0; j < 4; j++) {
			if (!board[i][j]) {
				isFull = false;
				break;
			}
		}
		if (isFull) {
			Ans++;
			return i;
		}
	}

	for (int i = 0; i < 4; i++) {
		if (board[1][i]) return 5;
	}

	return -1;
}

void downBlock(bool board[][4], int x) {
	for (int i = x; i >= 0; i--) {
		for (int j = 0; j < 4; j++) {
			if (i == 0) board[i][j] = false;
			else board[i][j] = board[i - 1][j];
		}
	}
}

int countBlock(bool board[][4]) {
	int result = 0;
	for (int i = 2; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			if (board[i][j]) result++;
		}
	}
	return result;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int n, t, x, y;

	cin >> n;
	while (n--) {
		cin >> t >> x >> y;
		setBlock(Green, t, x, y);
		transPos(&t, &x, &y);
		setBlock(Blue, t, x, y);

		int pos = -1;
		while ((pos = checkRow(Green)) != -1) downBlock(Green, pos);
		while ((pos = checkRow(Blue)) != -1) downBlock(Blue, pos);
	}

	cout << Ans << "\n";
	cout << countBlock(Green) + countBlock(Blue) << "\n";

	return 0;
}