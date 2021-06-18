#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 20
#define INF 987654321
using namespace std;

int dx[5] = { 0, 0, 0, -1, 1 };
int dy[5] = { 0, -1, 1, 0, 0 };

int N, Answer = INF;
bool board[MAX][MAX];

void init() {
	// N: ���� ���� ũ��
	cin >> N;

	// ���� �� �Է�
	bool inp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
}

// x, y ���� �����¿� ���� ���º�ȭ
void click(int x, int y, bool (*arr)[MAX]) {
	for (int i = 0; i < 5; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
		arr[nx][ny] = !arr[nx][ny];
	}
}

// �ʿ��� Ŭ�� Ƚ��
int countClick() {

	// �ӽ� �迭�� ����
	bool tempBoard[MAX][MAX];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			tempBoard[i][j] = board[i][j];
		}
	}

	// �ٷ� ���� ������ �����ִٸ� Ŭ��
	int res = 0;
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!tempBoard[i - 1][j]) continue;
			click(i, j, tempBoard);
			res++;
		}
	}

	// ��� ������ �������� Ȯ��
	for (int i = 0; i < N; i++) {
		if (tempBoard[N - 1][i]) return INF;
	}

	return res;
}

void solve(int pos, int cnt) {
	
	// ������ ��ȭ �Ϸ�
	if (pos == N) {
		Answer = min(Answer, countClick() + cnt);
		return;
	}

	// ��ȭ ���� ����
	solve(pos + 1, cnt);

	// ����ġ Ŭ�� �� ����
	click(0, pos, board);
	solve(pos + 1, cnt + 1);
	click(0, pos, board);	// ����
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	init();
	solve(0, 0);
	cout << (Answer != INF ? Answer : -1);

	return 0;
}