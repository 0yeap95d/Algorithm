#include <iostream>
#include <vector>
#include <queue>
#define SIZE 501
using namespace std;

int N, M, ans = -1;
vector<int> graph[SIZE];
bool visited[SIZE];
queue<pair<int, int>> que;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> M;

	// 친구 리스트 입력
	int v1, v2;
	for (int i = 0; i < M; i++) {
		cin >> v1 >> v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}

	visited[1] = true;
	que.push({ 1, 0 });
	while (!que.empty()) {
		int num = que.front().first;
		int cnt = que.front().second;
		que.pop();

		if (cnt > 2) continue;

		ans++;
		for (int n : graph[num]) {
			if (visited[n]) continue;
			visited[n] = true;
			que.push({ n, cnt + 1 });
		}
	}

	cout << ans;

	return 0;
}