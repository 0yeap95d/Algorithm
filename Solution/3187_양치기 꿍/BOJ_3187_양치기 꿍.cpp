#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
조건
1. 같은 울타리 영역 안에서 양이 늑대보다 많으면 늑대가 전부 잡아먹힘 (양 > 늑대)
2. 그 외의 경우 양이 전부 잡아먹힘 (양 <= 늑대)
*/

int R, C;
vector<vector<char>> map;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	// 입력 | 빈 공간 '.', 울타리 '#', 늑대 'v', 양 'k'
	cin >> R >> C;
	map.assign(R, vector<char>(C, 0));
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			cin >> map[r][c];
		}
	}

	int ans[2] = { 0, };
	int sheep, wolf;
	queue<pair<int, int>> que;
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			
			// 울타리일 때
			if (map[r][c] == '#') continue;

			// 울타리 아닐 때, 영역 안에 검사
			que.push({ r, c });
			sheep = wolf = 0;

			if (map[r][c] == 'v') wolf++;
			else if (map[r][c] == 'k') sheep++;
			map[r][c] = '#';

			while (!que.empty()) {
				int x = que.front().first;
				int y = que.front().second;
				que.pop();

				// 사방위 탐색
				for (int i = 0; i < 4; i++) {
					int nx = x + dx[i];
					int ny = y + dy[i]; 
					if (nx < 0 || nx >= R || ny < 0 || ny >= C || map[nx][ny] == '#') continue;
					que.push({ nx, ny });
					if (map[nx][ny] == 'v') wolf++;
					else if (map[nx][ny] == 'k') sheep++;
					map[nx][ny] = '#';
				}
			}

			if (sheep > wolf) wolf = 0;
			else sheep = 0;

			ans[0] += sheep;
			ans[1] += wolf;
		}
	}

	cout << ans[0] << " " << ans[1];


	return 0;
}