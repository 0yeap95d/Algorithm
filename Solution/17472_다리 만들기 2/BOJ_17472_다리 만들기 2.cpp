#include <iostream>
#include <queue> 
#include <algorithm>
using namespace std;

int getParent(int set[], int x) {
	if (set[x] == x) return x;
	return set[x] = getParent(set, set[x]);
}

void unionParent(int set[], int a, int b) {
	a = getParent(set, a);
	b = getParent(set, b);

	if (a < b) set[b] = a;
	else set[a] = b;
}

int find(int set[], int a, int b) {
	a = getParent(set, a);
	b = getParent(set, b);
	if (a == b) return 1;
	else return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// n,m : 1이상 10이하
	int n, m;
	cin >> n >> m;

	// 1. map 입력
	int map[11][11];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	// 2. 각 섬에 넘버링 (사방탐색, BFS)
	int dx[4] = { -1, 0, 1, 0 };
	int dy[4] = { 0, 1, 0, -1 };
	int number = 1;
	queue<pair<int, int>> que;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] != 1) continue;
			que.push(make_pair(i, j));
			map[i][j] = ++number;
			while (!que.empty()) {
				pair<int, int> pos = que.front();
				que.pop();
				for (int k = 0; k < 4; k++) {
					int nx = pos.first + dx[k];
					int ny = pos.second + dy[k];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m || map[nx][ny] != 1) continue;
					que.push(make_pair(nx, ny));
					map[nx][ny] = number;
				}
			}
		}
	}

	// 3. 각 섬에서 다른 섬으로 갈 수 있는 거리 그래프생성
	int graph[10][10] = { 0, };
	pair<int, int> dis;

	// 3-1. 가로 거리 구하기
	for (int i = 0; i < n; i++) {
		dis = make_pair(0, 0);
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) continue;
			if (dis.first == 0) dis = make_pair(map[i][j], j);
			else if (dis.first == map[i][j]) dis.second = j;
			else if (dis.first != map[i][j]) {
				int num = dis.first;
				int posX = dis.second;
				int dif = j - posX - 1;
				dis = make_pair(map[i][j], j);
				if (dif < 2) continue;
				
				if (graph[num][map[i][j]] != 0)
					dif = min(dif, graph[num][map[i][j]]);
				graph[num][map[i][j]] = dif;
				graph[map[i][j]][num] = dif;
			}
		}
	}

	// 3-1. 세로 거리 구하기
	for (int j = 0; j < m; j++) {
		dis = make_pair(0, 0);
		for (int i = 0; i < n; i++) {
			if (map[i][j] == 0) continue;
			if (dis.first == 0) dis = make_pair(map[i][j], i);
			else if (dis.first == map[i][j]) dis.second = i;
			else if (dis.first != map[i][j]) {
				int num = dis.first;
				int posY = dis.second;
				int dif = i - posY - 1;
				dis = make_pair(map[i][j], i);
				if (dif < 2) continue;

				if (graph[num][map[i][j]] != 0)
					dif = min(dif, graph[num][map[i][j]]);
				graph[num][map[i][j]] = dif;
				graph[map[i][j]][num] = dif;
			}
		}
	}

	// 4. 최단거리구하기 (MST)
	int check[10];
	for (int i = 0; i < 10; i++) check[i] = i;
	priority_queue<pair<int, pair<int, int>>> pq;
	for (int i = 2; i <= number; i++) {
		for (int j = i + 1; j <= number; j++) {
			if (graph[i][j] == 0) continue;
			pq.push(make_pair(-graph[i][j], make_pair(i, j)));
		}
	}

	int ans = 0;
	while (!pq.empty()) {
		int v1 = pq.top().second.first;
		int v2 = pq.top().second.second;
		int val = -pq.top().first;
		pq.pop();
		if (find(check, v1, v2)) continue;
		ans += val;
		unionParent(check, v1, v2);
	}

	// 5. 모두 연결되어있는지 판단
	int cnt = 0;
	for (int i = 2; i <= number; i++) {
		if (check[i] == i) cnt++;
	}
	if (cnt != 1) ans = -1;
	cout << ans; 

	return 0;
}