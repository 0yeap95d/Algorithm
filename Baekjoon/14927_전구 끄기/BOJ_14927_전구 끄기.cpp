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
	// N: 전구 판의 크기
	cin >> N;

	// 전구 판 입력
	bool inp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
}

// x, y 포함 상하좌우 전구 상태변화
void click(int x, int y, bool (*arr)[MAX]) {
	for (int i = 0; i < 5; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
		arr[nx][ny] = !arr[nx][ny];
	}
}

// 필요한 클릭 횟수
int countClick() {

	// 임시 배열에 복사
	bool tempBoard[MAX][MAX];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			tempBoard[i][j] = board[i][j];
		}
	}

	// 바로 위의 전구가 켜져있다면 클릭
	int res = 0;
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!tempBoard[i - 1][j]) continue;
			click(i, j, tempBoard);
			res++;
		}
	}

	// 모든 전구가 꺼졌는지 확인
	for (int i = 0; i < N; i++) {
		if (tempBoard[N - 1][i]) return INF;
	}

	return res;
}

void solve(int pos, int cnt) {
	
	// 전구판 변화 완료
	if (pos == N) {
		Answer = min(Answer, countClick() + cnt);
		return;
	}

	// 변화 없이 다음
	solve(pos + 1, cnt);

	// 스위치 클릭 후 다음
	click(0, pos, board);
	solve(pos + 1, cnt + 1);
	click(0, pos, board);	// 복구
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	init();
	solve(0, 0);
	cout << (Answer != INF ? Answer : -1);

	return 0;
}