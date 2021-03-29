#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <algorithm>
#define pii pair<int, int>
using namespace std;

int N, Q, L;
vector<vector<int>> ice, temp;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void rotateIce(int l, int n, pii start) {
	if (l == n) {
		int x = start.first;
		int y = start.second;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				ice[x + j][(n + y - 1) - i] = temp[x + i][y + j];
			}
		}
	
		return;
	}

	int x = start.first;
	int y = start.second;

	rotateIce(l, n / 2, { x, y });
	rotateIce(l, n / 2, { x, y + (n / 2)});
	rotateIce(l, n / 2, { x + (n / 2), y });
	rotateIce(l, n / 2, { x + (n / 2), y + (n / 2)});
}

void meltIce() {

	vector<pii> meltPos;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (ice[i][j] == 0) continue;

			int cnt = 0;
			for (int d = 0; d < 4; d++) {
				int nx = i + dx[d];
				int ny = j + dy[d];
				if (nx < 0 || nx >= N || ny < 0 || ny >= N || ice[nx][ny] == 0) continue;
				cnt++;
			}

			if (cnt < 3) meltPos.push_back({ i, j });
		}
	}

	for (pii p : meltPos) ice[p.first][p.second]--;
}

void fireStom(int l, int n, pii start) {
	// 회전 | L이 0이거나 N과 같으면 회전하지 않음
	if (l != n || l != 0) rotateIce(l, n, start);

	// 얼음 녹음
	meltIce();
}

int sumIce() {
	int sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			sum += ice[i][j];
		}
	}
	return sum;
}

int cntIce() {

	int ret = 0;
	queue<pair<int, int>> que;
	vector<vector<bool>> visited(N, vector<bool>(N, false));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] || ice[i][j] == 0) continue;
				
			que.push({ i, j });
			visited[i][j] = true;
			int cnt = 1;

			while (!que.empty()) {
				int x = que.front().first;
				int y = que.front().second;
				que.pop();

				for (int i = 0; i < 4; i++) {
					int nx = x + dx[i];
					int ny = y + dy[i];

					if (nx < 0 || nx >= N || ny < 0 || ny >= N || visited[nx][ny] || ice[nx][ny] == 0) continue;
					que.push({ nx, ny });
					visited[nx][ny] = true;
					cnt++;
				}
			}
			ret = max(ret, cnt);
		}
	}

	return ret;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> Q;
	N = pow(2, N);
	ice.assign(N, vector<int>(N, 0));

	// 얼음 입력
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> ice[i][j];
		}
	}

	// 파이어스톰 시전
	for (int i = 0; i < Q; i++) {
		cin >> L;
		temp.assign(ice.begin(), ice.end());
		fireStom(pow(2, L), N, { 0, 0 });
	}

	cout << sumIce() << "\n";
	cout << cntIce() << "\n";

	return 0;
}