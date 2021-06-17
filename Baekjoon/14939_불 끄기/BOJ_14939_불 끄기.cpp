#include <iostream>
#include <algorithm>
#define MAX 10
#define INF 987654321
using namespace std;

int dx[5] = { 0, 0, 0, -1, 1 }; 
int dy[5] = { 0, -1, 1, 0, 0 };

int Answer = INF;
bool bulbs[MAX][MAX];

// 전구 상태 입력
void setBulbs() {
	char ch;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			cin >> ch;
			if (ch == 'O') bulbs[i][j] = true;
		}
	}
}

// 전구 상태 변경 (상하좌우 4칸도 함께)
void clickBulbs(bool (*arr)[MAX], int x, int y) {
	for (int i = 0; i < 5; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= MAX || ny < 0 || ny >= MAX) continue;
		arr[nx][ny] = !arr[nx][ny];
	}
}

// 변경해야할 전구 카운트
int countClick() {

	// 배열 복사
	bool tempBulbs[MAX][MAX];
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			tempBulbs[i][j] = bulbs[i][j];
		}
	}

	// 필요한 클릭 카운트
	int res = 0;
	for (int i = 1; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			if (tempBulbs[i - 1][j] == true) {
				clickBulbs(tempBulbs, i, j);
				res++;
			}
		}
	}

	// 모든 불이 꺼졌는지 확인
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