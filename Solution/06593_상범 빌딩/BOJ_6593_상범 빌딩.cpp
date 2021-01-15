#include <iostream>
#include <cstring>
#include <queue>
#define SIZE 31
using namespace std;

struct Pos {
	int l;
	int r;
	int c;
	int t;
};

int L, R, C;
char building[SIZE][SIZE][SIZE];
bool visited[SIZE][SIZE][SIZE];

int dl[6] = { 0, 0, 0, 0, 1, -1 };
int dr[6] = { 0, 0, -1, 1, 0, 0};
int dc[6] = { -1, 1, 0, 0, 0, 0 };

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	while (cin >> L >> R >> C) {
		if (L == 0 && R == 0 && C == 0) break;

		memset(visited, false, sizeof(visited));

		// 빌딩 정보 입력
		Pos start, end;
		for (int l = 0; l < L; l++) {
			for (int r = 0; r < R; r++) {
				cin >> building[l][r];
				for (int c = 0; c < C; c++) {
					if (building[l][r][c] == '#') visited[l][r][c] = true;
					else if (building[l][r][c] == 'S') start = { l, r, c, 0 };
					else if (building[l][r][c] == 'E') end = { l, r, c, 0 };
				}
			}
		}

		// 이동
		queue<Pos> que;
		visited[start.l][start.r][start.c] = true;
		que.push(start);

		int time = 0;
		while (!que.empty()) {

			int l = que.front().l;
			int r = que.front().r;
			int c = que.front().c;
			int t = que.front().t;
			que.pop();

			for (int i = 0; i < 6; i++) {
				int nl = l + dl[i];
				int nr = r + dr[i];
				int nc = c + dc[i];

				if (nl < 0 || nl >= L || nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
				if (visited[nl][nr][nc]) continue;

				if (end.l == nl && end.r == nr && end.c == nc) {
					time = ++t;
					break;
				}

				visited[nl][nr][nc] = true;
				que.push({ nl, nr, nc, t + 1 });
			}

			if (time) break;
		}

		if (time) cout << "Escaped in " << time << " minute(s).\n";
		else cout << "Trapped!\n";
	}

	return 0;
}