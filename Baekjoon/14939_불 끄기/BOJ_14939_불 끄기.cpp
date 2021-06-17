#include <iostream>
#include <algorithm>
#define MAX 10
#define INF 987654321
using namespace std;

int dx[5] = { 0, 0, 0, -1, 1 }; 
int dy[5] = { 0, -1, 1, 0, 0 };

int Answer = INF;
bool bulbs[MAX][MAX];

// ���� ���� �Է�
void setBulbs() {
	char ch;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			cin >> ch;
			if (ch == 'O') bulbs[i][j] = true;
		}
	}
}

// ���� ���� ���� (�����¿� 4ĭ�� �Բ�)
void clickBulbs(bool (*arr)[MAX], int x, int y) {
	for (int i = 0; i < 5; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= MAX || ny < 0 || ny >= MAX) continue;
		arr[nx][ny] = !arr[nx][ny];
	}
}

// �����ؾ��� ���� ī��Ʈ
int countClick() {

	// �迭 ����
	bool tempBulbs[MAX][MAX];
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			tempBulbs[i][j] = bulbs[i][j];
		}
	}

	// �ʿ��� Ŭ�� ī��Ʈ
	int res = 0;
	for (int i = 1; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			if (tempBulbs[i - 1][j] == true) {
				clickBulbs(tempBulbs, i, j);
				res++;
			}
		}
	}

	// ��� ���� �������� Ȯ��
	for (int i = 0; i < MAX; i++) {
		if (tempBulbs[MAX - 1][i]) return INF;
	}

	return res;
}

void solve(int idx, int cnt) {
	if (idx == MAX) {
		Answer = min(Answer, countClick() + cnt);
		return;
	}

	solve(idx + 1, cnt);
	clickBulbs(bulbs, 0, idx);
	solve(idx + 1, cnt + 1);
	clickBulbs(bulbs, 0, idx);
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	setBulbs();
	solve(0, 0);
	cout << (Answer == INF ? -1 : Answer);

	return 0;
}