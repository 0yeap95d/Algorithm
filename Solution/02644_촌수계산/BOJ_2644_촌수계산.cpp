#include <iostream>
#include <vector>
#include <queue>
#define SIZE 101
using namespace std;

int N, M, sp, ep;
vector<int> graph[SIZE];
bool visited[SIZE];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> sp >> ep >> M;

	// 부모 자식들 간의 관계 입력
	int v1, v2;
	for (int i = 1; i <= M; i++) {
		cin >> v1 >> v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}

	// sp, ep 간의 촌수 계산
	queue<pair<int, int>> que;
	que.push({ sp, 0 });

	int ans = -1;
	while (!que.empty()) {
		int v = que.front().first;
		int cnt = que.front().second;
		que.pop();

		if (v == ep) {
			ans = cnt;
			break;
		}
		
		for (int nv : graph[v]) {
			if (visited[nv]) continue;
			que.push({ nv, cnt + 1 });
			visited[nv] = true;
		}
	}

	cout << ans;

	return 0;
}