#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#define SIZE 21
#define INF 987654321
using namespace std;

int W, H, Ans;
int Room[SIZE][SIZE], Edge[SIZE][SIZE];
bool visited[SIZE][SIZE];
pair<int, int> Pos[SIZE];
queue<pair<int, pair<int, int>>> que;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	while (cin >> W >> H) {
		if (W == 0 && H == 0) break;

		// 초기화
		Ans = INF;
		memset(Room, 0, sizeof(Room));
		memset(Edge, 0, sizeof(Edge));

		// 입력
		char inp; int num = 1;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> inp;
				if (inp == '.') Room[i][j] = 0;
				else if (inp == 'o') {
					Room[i][j] = 1;
					Pos[1] = { i, j };
				}
				else if (inp == '*') {
					Room[i][j] = ++num;
					Pos[num] = { i, j };
				}
				else if (inp == 'x') Room[i][j] = -1;
			}
		}

		// BFS를 이용해 각 정점간 거리 계산
		for (int i = 1; i <= num; i++) {
			memset(visited, 0, sizeof(visited));
			while (!que.empty()) que.pop();
			que.push({ 0, Pos[i] });
			
			while (!que.empty()) {
				int x = que.front().second.first;
				int y = que.front().second.second;
				int dis = que.front().first;
				que.pop();

				for (int di = 0; di < 4; di++) {
					int nx = x + dx[di];
					int ny = y + dy[di];

					if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
					if (visited[nx][ny] || Room[nx][ny] == -1) continue;

					int idx = Room[nx][ny];
					if (idx != 0 && Edge[i][idx] == 0) Edge[i][idx] = Edge[idx][i] = dis + 1;

					que.push({ dis + 1, { nx, ny } });
					visited[nx][ny] = true;
				}
			}
		}

		// 방문할 수 없는 더러운 칸이 존재하는 경우
		for (int i = 2; i <= num; i++)
			if (Edge[1][i] == 0) Ans = -1;
		

		// 조합을 이용하여 모든 경우의 수 탐색
		if (Ans != -1) {
			vector<int> perm;
			for (int i = 1; i <= num; i++) perm.push_back(i);

			do {
				int sum = 0;
				for (int i = 0; i < num - 1; i++)
					sum = sum + Edge[perm[i]][perm[i + 1]];
				Ans = min(Ans, sum);
			} while (next_permutation(perm.begin() + 1, perm.end()));
		}

		cout << Ans << "\n";
	}

	return 0;
}