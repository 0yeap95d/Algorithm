#include <iostream>
#include <cstring>
#include <queue>
#define SIZE 251
using namespace std;

int R, C, Sheep, Wolf;
string Yard[SIZE];
bool visited[SIZE][SIZE];
queue<pair<int, int>> que;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> Yard[i];
		for (int j = 0; j < C; j++) {
			if (Yard[i][j] == '#') visited[i][j] = true;
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (visited[i][j]) continue;
			que.push({ i, j });
			visited[i][j] = true;

			bool escape = false;
			int cntSheep, cntWolf;
			cntSheep = cntWolf = 0;
			while (!que.empty()) {
				int x = que.front().first;
				int y = que.front().second;
				que.pop();

				if (Yard[x][y] == 'v') cntWolf++;
				else if (Yard[x][y] == 'o') cntSheep++;

				for (int di = 0; di < 4; di++) {
					int nx = x + dx[di];
					int ny = y + dy[di];
					if (nx < 0 || nx >= R || ny < 0 || ny >= C) {
						escape = true;
						continue;
					}
					if (visited[nx][ny]) continue;
					que.push({ nx, ny });
					visited[nx][ny] = true;
				}
			}

			if (escape) continue;
			else if (cntSheep > cntWolf) Sheep = Sheep + cntSheep;
			else Wolf = Wolf + cntWolf;
		}
	}

	cout << Sheep << " " << Wolf;

	return 0;
}