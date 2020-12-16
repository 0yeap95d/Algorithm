#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 987654321
using namespace std;

int N, M, D, ans = 0;
vector<vector<int>> map;

int attack(vector<int> pos) {
	pair<int, pair<int, int>> enemy[3];	// 거리, x좌표, y좌표
	vector<vector<int>> visited(map.begin(), map.end());
	
	int ret = 0;
	for (int n = N; n >= 0; n--) {
		for (int i = 0; i < 3; i++) enemy[i].first = MAX;
		
		// 적이 내려오는 대신 궁수가 한칸씩 올라간다고 가정
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < M; j++) {
				if (visited[i][j] == 0) continue;
				for (int idx = 0; idx < 3; idx++) {
					int dis = (n - i) + abs(pos[idx] - j);
					// 사정거리 밖
					if (dis > D) continue;
					// 저장된 거리보다 더 멀리 있을 때
					if (enemy[idx].first < dis) continue;
					// 저장된 거리보다 더 짧을때
					else if (enemy[idx].first > dis) enemy[idx] = make_pair(dis, make_pair(i, j));
					// 거리 같으면서 더 왼쪽에 있을 때
					else if (enemy[idx].second.second > j) enemy[idx] = make_pair(dis, make_pair(i, j));
				}
			}
		}

		for (int i = 0; i < 3; i++) {
			if (enemy[i].first == MAX) continue;
			int x = enemy[i].second.first;
			int y = enemy[i].second.second;
			ret += visited[x][y];
			visited[x][y] = 0;
		}
	}

	return ret;
}

void setArcher(int idx, vector<int> pos) {

	if (pos.size() >= 3) {
		ans = max(ans, attack(pos));
		return;
	}

	if (idx >= M) return;

	setArcher(idx + 1, pos);
	pos.push_back(idx);
	setArcher(idx + 1, pos);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> D;
	map.assign(N, vector<int>(M, false));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	setArcher(0, vector<int>());

	cout << ans;

	return 0;
}