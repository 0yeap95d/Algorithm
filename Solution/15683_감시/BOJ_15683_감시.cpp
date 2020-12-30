#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, ans = 987654321;
vector<vector<int>> map;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

// CCTV 위치 찾기
pair<int, int> findCCTV(vector<vector<int>> office) {
	pair<int, int> ret(-1, -1);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (office[i][j] != -1 && office[i][j] != 0 && office[i][j] != 6) {
				ret.first = i;
				ret.second = j;
				return ret;
			}
		}
	}

	return ret;
}

// CCTV가 바라보는 방향으로 채우기
void setCCTV(vector<vector<int>> &office, pair<int, int> pos, int dir) {
	int nx = pos.first;
	int ny = pos.second;
	while (1) {
		nx = nx + dx[dir];
		ny = ny + dy[dir];

		if (nx < 0 || nx >= N || ny < 0 || ny >= M || office[nx][ny] == 6) break;

		if (office[nx][ny] == 0) office[nx][ny] = -1;
		else continue;
	}
}

void DFS(vector<vector<int>> office) {
	
	pair<int, int> pos = findCCTV(office);
	
	// 더 이상 남아있는 CCTV가 없을 때
	if (pos.first == -1 && pos.second == -1) {
		int blindSpot = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (office[i][j] == 0) blindSpot++;
			}
		}
		ans = min(ans, blindSpot);
		return;
	}

	int val = map[pos.first][pos.second];
	vector<vector<int>> temp;
	if (val == 1) {
		for (int i = 0; i < 4; i++) {
			temp.assign(office.begin(), office.end());
			setCCTV(temp, pos, i);
			temp[pos.first][pos.second] = -1;
			DFS(temp);
		}
	}
	else if (val == 2) {
		for (int i = 0; i < 2; i++) {
			temp.assign(office.begin(), office.end());
			setCCTV(temp, pos, i);
			setCCTV(temp, pos, i + 2);
			temp[pos.first][pos.second] = -1;
			DFS(temp);
		}
	}
	else if (val == 3) {
		for (int i = 0; i < 4; i++) {
			temp.assign(office.begin(), office.end());
			setCCTV(temp, pos, i);
			setCCTV(temp, pos, (i + 1) % 4);
			temp[pos.first][pos.second] = -1;
			DFS(temp);
		}
	}
	else if (val == 4) {
		for (int i = 0; i < 4; i++) {
			temp.assign(office.begin(), office.end());
			setCCTV(temp, pos, i);
			setCCTV(temp, pos, (i + 1) % 4);
			setCCTV(temp, pos, (i + 2) % 4);
			temp[pos.first][pos.second] = -1;
			DFS(temp);
		}
	}
	else if (val == 5) {
		temp.assign(office.begin(), office.end());
		for (int i = 0; i < 4; i++) setCCTV(temp, pos, i);
		temp[pos.first][pos.second] = -1;
		DFS(temp);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// 사무실 입력
	cin >> N >> M;
	map.assign(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	DFS(map);

	cout << ans;

	return 0;
}