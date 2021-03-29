#include <iostream>
#include <queue>
#include <cstring>
#include <map>
#define SIZE 102
using namespace std;

int testcase;
int H, W, Ans;
char Building[SIZE][SIZE];
bool visited[SIZE][SIZE];
bool keys[27];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> testcase;
	while (testcase--) {

		Ans = 0;
		memset(Building, 0, sizeof(Building));
		memset(visited, 0, sizeof(visited));
		memset(keys, 0, sizeof(keys));

		// 빌딩 정보 입력
		cin >> H >> W;
		for (int i = 1; i <= H; i++) {
			for (int j = 1; j <= W; j++) {
				cin >> Building[i][j];
			}
		}

		queue<pair<int, int>> que;
		queue<pair<int, int>> save[26];
		que.push({ 0, 0 });

		string inp;
		cin >> inp;
		for (char i : inp) {
			if (i == '0') break;
			keys[i - 'a'] = true;
		}

		while (!que.empty()) {
			int x = que.front().first;
			int y = que.front().second;
			que.pop();

			if (Building[x][y] == '$') {
				Building[x][y] = '.';
				Ans++;
			}

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || nx > H + 1 || ny < 0 || ny > W + 1) continue;
				if (Building[nx][ny] == '*' || visited[nx][ny]) continue;
				char pos = Building[nx][ny];

				// 대문자
				if (pos >= 'A' && pos <= 'Z') {
					int idx = pos - 'A';
					if (keys[idx]) que.push({ nx, ny });
					else save[idx].push({ nx, ny });
					visited[nx][ny] = true;
				}

				// 소문자
				else if (pos >= 'a' && pos <= 'z') {
					int idx = pos - 'a';
					que.push({ nx, ny });
					visited[nx][ny] = keys[idx] = true;
					while (!save[idx].empty()) {
						que.push(save[idx].front());
						save[idx].pop();
					}
				}

				else {
					que.push({ nx, ny });
					visited[nx][ny] = true;
				}
			}
		}
		
		cout << Ans << "\n";
	}

	return 0;
}

