#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

struct Virus {
	int x;
	int y;
	int time;
};

int N, M, area, ans = INF;
int lab[51][51];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
vector<Virus> posVir;


// 바이러스 퍼뜨림(BFS)
void spreadVir(vector<Virus> actVir) {
	queue<Virus> que;
	vector<vector<bool>> visited(N, vector<bool>(N, false));

	for (int i = 0; i < actVir.size(); i++) {
		visited[actVir[i].x][actVir[i].y] = true;
		que.push(actVir[i]);
	}

	int x, y, t, cnt = area;
	x = y = t = 0;
	while (!que.empty()) {
		x = que.front().x;
		y = que.front().y;
		t = que.front().time;
		que.pop();

		if (lab[x][y] == 0) cnt--;
		if (cnt == 0) break;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (lab[nx][ny] == 1 || visited[nx][ny]) continue;

			visited[nx][ny] = true;
			que.push({ nx, ny, t + 1 });
		}
	}

	if (cnt == 0) ans = min(ans, t);
}


// M개의 바이러스 선택
void selectVir(int idx, int cnt, vector<Virus> vir) {
	if (cnt == M) {
		spreadVir(vir);
		return;
	}

	if (idx >= posVir.size()) return;

	selectVir(idx + 1, cnt, vir);
	vir.push_back(posVir[idx]);
	selectVir(idx + 1, cnt + 1, vir);
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// 연구소 크기 N, 바이러스 개수 M
	cin >> N >> M;

	// 연구소 상태 입력
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> lab[i][j];
			if (lab[i][j] == 2) posVir.push_back({ i, j, 0 });
			else if (lab[i][j] == 0) area++;
		}
	}

	// 바이러스 선택 후 전파
	selectVir(0, 0, vector<Virus>());

	if (ans == INF) ans = -1;
	cout << ans;

	return 0;
}