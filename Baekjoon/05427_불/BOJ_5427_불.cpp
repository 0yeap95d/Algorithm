#include <iostream>
#include <queue>
#define SIZE 1001
using namespace std;

int testCase;
int W, H;
char building[SIZE][SIZE];
bool visited[2][SIZE][SIZE];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// 테스트케이스 개수
	cin >> testCase;

	while (testCase--) {

		// 변수 초기화
		for (int h = 0; h < H; h++) {
			for (int w = 0; w < W; w++) {
				building[h][w] = '.';
				visited[0][h][w] = visited[1][h][w] = false;
			}
		}

		// 빌딩 너비 w, 높이 h
		cin >> W >> H;

		// 빌딩 입력
		for (int h = 0; h < H; h++) {
			cin >> building[h];
		}

		// 불, 벽, 상근 위치 저장
		queue<pair<int, int>> fire, posFire, sangGeun, posSangGeun;
		for (int h = 0; h < H; h++) {
			for (int w = 0; w < W; w++) {
				if (building[h][w] == '*') {
					visited[0][h][w] = visited[1][h][w] = true;
					posFire.push({ h, w });
				}
				else if (building[h][w] == '@') {
					visited[1][h][w] = true;
					posSangGeun.push({ h, w });
				}
				else if (building[h][w] == '#') visited[0][h][w] = visited[1][h][w] = true;
			}
		}

		// 상근이가 움직일 수 없거나 탈출하면 종료
		int isEscape = 0;
		int time = 0;
		while (!posSangGeun.empty() && isEscape == 0) {
			time++;

			// 불 시작 위치
			while (!posFire.empty()) {
				fire.push(posFire.front());
				posFire.pop();				
			}

			// 불 이동
			while (!fire.empty()) {
				int x = fire.front().first;
				int y = fire.front().second;
				fire.pop();

				for (int di = 0; di < 4; di++) {
					int nx = x + dx[di];
					int ny = y + dy[di];

					// 빌딩 범위 체크
					if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;

					// 이미 불이 붙어있는 곳 체크
					if (visited[0][nx][ny]) continue;

					visited[0][nx][ny] = visited[1][nx][ny] = true;
					posFire.push({ nx, ny });
				}
			}


			// 상근 시작 위치
			while (!posSangGeun.empty()) {
				sangGeun.push(posSangGeun.front());
				posSangGeun.pop();				
			}

			// 상근 이동
			while (!sangGeun.empty()) {
				int x = sangGeun.front().first;
				int y = sangGeun.front().second;
				sangGeun.pop();

				for (int di = 0; di < 4; di++) {
					int nx = x + dx[di];
					int ny = y + dy[di];

					// 탈출 성공
					if (nx < 0 || nx >= H || ny < 0 || ny >= W) {
						isEscape = time;
						break;
					}
					
					// 들렀던 곳, 불 있는 곳 체크
					if (visited[0][nx][ny] || visited[1][nx][ny]) continue;

					visited[1][nx][ny] = true;
					posSangGeun.push({ nx, ny });
				}
			}
		}

		// 정답 출력
		if (isEscape == 0) cout << "IMPOSSIBLE\n";
		else cout << isEscape << "\n";
	}

	return 0;
}