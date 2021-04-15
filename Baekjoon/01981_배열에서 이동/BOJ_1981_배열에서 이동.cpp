#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int N, maxVal, minVal, answer;
vector<vector<int>> arr;
vector<vector<bool>> visited;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

bool BFS(int gap) {

	for (int i = minVal; i <= maxVal; i++) {

		visited.assign(N, vector<bool>(N, true));

		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				if (i <= arr[r][c] && arr[r][c] <= i + gap)
					visited[r][c] = false;
			}
		}

		queue<pair<int, int>> que;
		if (!visited[0][0]) {
			que.push({ 0, 0 });
			visited[0][0] = true;
		}		

		while (!que.empty()) {
			int x = que.front().first;
			int y = que.front().second;
			que.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
				if (visited[nx][ny]) continue;
				if (nx == N - 1 && ny == N - 1) return true;

				que.push({ nx, ny });
				visited[nx][ny] = true;
			}
		}
	}

	return false;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N;
	arr.resize(N, vector<int>(N));
	minVal = 201, maxVal = -1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			minVal = min(minVal, arr[i][j]);
			maxVal = max(maxVal, arr[i][j]);
		}
	}

	int low = 0;
	int high = maxVal - minVal;
	int mid = 0;
	while (low <= high) {
		mid = (low + high) / 2;
		if (BFS(mid)) high = mid - 1;
		else low = mid + 1;
	}
	answer = high + 1;

	cout << answer;

	return 0;
}