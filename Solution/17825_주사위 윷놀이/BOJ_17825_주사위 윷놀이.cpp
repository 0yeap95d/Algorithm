#include <iostream>
#include <algorithm>
using namespace std;

int board[4][30] = {
	{-1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20},
	{5, 21, 22, 23, 29, 30, 31, 20},
	{10, 24, 25, 29, 30, 31, 20},
	{15, 26, 27, 28, 29, 30, 31, 20}
};
int score[32] = { 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 13, 16, 19, 22, 24, 28, 27, 26, 25, 30, 35 };

int Answer, dice[10];
pair<int, int> horse[4];
bool visited[32];

void solve(int idx, int sum) {
	
	if (idx == 10) {
		Answer = max(Answer, sum);
		return;
	}

	for (int i = 0; i < 4; i++) {
		// 현재 위치
		int x = horse[i].first;
		int y = horse[i].second;
		int pos = board[x][y];

		// 이미 도착한 말인 경우
		if (pos == 0) continue;

		// 이동할 위치
		int ny = y + dice[idx];
		int nPos = board[x][ny];
		
		// 이동할 위치에 다른 말이 존재
		if (visited[nPos]) continue;

		// 경로설정
		if (nPos == 5) horse[i] = { 1, 0 };
		else if (nPos == 10) horse[i] = { 2, 0 };
		else if (nPos == 15) horse[i] = { 3, 0 };
		else horse[i] = { x, ny };

		// 방문체크
		if (pos != -1) visited[pos] = false;
		if (nPos != 0) visited[nPos] = true;

		solve(idx + 1, sum + score[nPos]);
		
		// 방문체크 해제
		horse[i] = { x, y };
		if (pos != -1) visited[pos] = true;
		if (nPos != 0) visited[nPos] = false;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	for (int i = 0; i < 10; i++) cin >> dice[i];
	solve(0, 0);
	cout << Answer;

	return 0;
}