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

	// �׽�Ʈ���̽� ����
	cin >> testCase;

	while (testCase--) {

		// ���� �ʱ�ȭ
		for (int h = 0; h < H; h++) {
			for (int w = 0; w < W; w++) {
				building[h][w] = '.';
				visited[0][h][w] = visited[1][h][w] = false;
			}
		}

		// ���� �ʺ� w, ���� h
		cin >> W >> H;

		// ���� �Է�
		for (int h = 0; h < H; h++) {
			cin >> building[h];
		}

		// ��, ��, ��� ��ġ ����
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

		// ����̰� ������ �� ���ų� Ż���ϸ� ����
		int isEscape = 0;
		int time = 0;
		while (!posSangGeun.empty() && isEscape == 0) {
			time++;

			// �� ���� ��ġ
			while (!posFire.empty()) {
				fire.push(posFire.front());
				posFire.pop();				
			}

			// �� �̵�
			while (!fire.empty()) {
				int x = fire.front().first;
				int y = fire.front().second;
				fire.pop();

				for (int di = 0; di < 4; di++) {
					int nx = x + dx[di];
					int ny = y + dy[di];

					// ���� ���� üũ
					if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;

					// �̹� ���� �پ��ִ� �� üũ
					if (visited[0][nx][ny]) continue;

					visited[0][nx][ny] = visited[1][nx][ny] = true;
					posFire.push({ nx, ny });
				}
			}


			// ��� ���� ��ġ
			while (!posSangGeun.empty()) {
				sangGeun.push(posSangGeun.front());
				posSangGeun.pop();				
			}

			// ��� �̵�
			while (!sangGeun.empty()) {
				int x = sangGeun.front().first;
				int y = sangGeun.front().second;
				sangGeun.pop();

				for (int di = 0; di < 4; di++) {
					int nx = x + dx[di];
					int ny = y + dy[di];

					// Ż�� ����
					if (nx < 0 || nx >= H || ny < 0 || ny >= W) {
						isEscape = time;
						break;
					}
					
					// �鷶�� ��, �� �ִ� �� üũ
					if (visited[0][nx][ny] || visited[1][nx][ny]) continue;

					visited[1][nx][ny] = true;
					posSangGeun.push({ nx, ny });
				}
			}
		}

		// ���� ���
		if (isEscape == 0) cout << "IMPOSSIBLE\n";
		else cout << isEscape << "\n";
	}

	return 0;
}