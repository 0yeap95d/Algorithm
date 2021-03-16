#include <iostream>
#include <algorithm>
#define SIZE 10
using namespace std;

int Answer = -1;
int paper[SIZE][SIZE];
int cntPaper[6];

bool checkPaper(int x, int y, int k) {
	for (int i = x; i < x + k; i++) {
		for (int j = y; j < y + k; j++) {
			if (i >= SIZE || j >= SIZE || paper[i][j] == 0) return false;
		}
	}
	return true;
}

void setPaper(int x, int y, int k, int value) {
	for (int i = x; i < x + k; i++) {
		for (int j = y; j < y + k; j++) {
			paper[i][j] = value;
		}
	}
}

void DFS(int sum) {
	if (Answer != -1 && sum >= Answer) return;

	bool isEnd = true;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (paper[i][j] == 0) continue;

			isEnd = false;
			for (int k = 5; k > 0; k--) {
				if (cntPaper[k] == 5) continue;
				if (!checkPaper(i, j, k)) continue;
				setPaper(i, j, k, 0);
				cntPaper[k]++;
				DFS(sum + 1);
				setPaper(i, j, k, 1);
				cntPaper[k]--;
			}
			break;
		}
		if (!isEnd) break;
	}

	if (isEnd) {
		if (Answer == -1) Answer = sum;
		else Answer = min(Answer, sum);
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cin >> paper[i][j];
		}
	}

	DFS(0);

	cout << Answer;

	return 0;
}