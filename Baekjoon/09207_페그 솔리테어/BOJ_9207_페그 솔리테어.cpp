#include <iostream>
#include <cstring>
#define HEIGHT 5
#define WIDTH 9
#define INF 987654321
using namespace std;

int testcase;
string board[5];
pair<int, int> answer;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

void nextGame(int round) {

	bool isNotMove = true;
	int countPin = 0;

	// 움직일 수 있는 핀 찾기, 핀의 개수
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			if (board[i][j] != 'o') continue;
			countPin++;

			for (int di = 0; di < 4; di++) {
				int nx = i + dx[di] * 2;
				int ny = j + dy[di] * 2;

				if (nx < 0 || nx >= HEIGHT || ny < 0 || ny >= WIDTH) continue;
				if (board[nx][ny] != '.' || board[nx - dx[di]][ny - dy[di]] != 'o') continue;

				board[nx][ny] = 'o';
				board[i][j] = board[nx - dx[di]][ny - dy[di]] = '.';
				nextGame(round + 1);
				board[nx][ny] = '.';
				board[i][j] = board[nx - dx[di]][ny - dy[di]] = 'o';

				isNotMove = false;
			}
		}
	}

	if (!isNotMove) return;

	// 움직일 수 있는 핀이 없는 경우
	if (countPin < answer.first || (countPin == answer.first && round < answer.second)) answer = { countPin, round };
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> testcase;
	while (testcase--) {
		// 게임판 입력
		answer = { INF, INF };
		for (int i = 0; i < 5; i++) cin >> board[i];

		// 게임 시작
		nextGame(0);
		cout << answer.first << " " << answer.second << "\n";
	}

	return 0;
}