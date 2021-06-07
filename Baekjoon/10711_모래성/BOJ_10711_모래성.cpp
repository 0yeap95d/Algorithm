#include <iostream>
#include <queue>
#define MAX 1001
using namespace std;

int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int H, W;
int sand[MAX][MAX];
queue<pair<int, int>> notCastle;

void Init() {
	cin >> H >> W;
	char ch;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> ch;
			if (ch == '.') {
				sand[i][j] = 0;
				notCastle.push({ i, j });
			}
			else sand[i][j] = ch - '0';
		}
	}
}

void BFS() {
	int answer = 0;
	queue<pair<int, int>> temp;

	while (1) {
		while (!notCastle.empty()) {
			int x = notCastle.front().first;
			int y = notCastle.front().second;
			notCastle.pop();

			for (int i = 0; i < 8; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || nx >= H || ny < 0 || ny >= W || !sand[nx][ny]) continue;
				sand[nx][ny]--;
				if (sand[nx][ny] == 0) temp.push({ nx, ny });
			}
		}

		if (temp.empty()) break;
		while (!temp.empty()) {
			notCastle.push(temp.front());
			temp.pop();
		}
		answer++;
	}

	cout << answer;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	Init();
	BFS();

	return 0;
}
