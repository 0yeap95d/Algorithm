#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define SIZE 100001
using namespace std;

int N, M, Ans;
vector<pair<int, int>> Path[SIZE];
bool Visited[SIZE];

struct cmp {
	bool operator()(pair<int, int> p1, pair<int, int> p2) {
		if (p1.second == p2.second) return p1.first > p2.first;
		return p1.second > p2.second;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> M;

	int a, b, c;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		Path[a].push_back({ b, c });
		Path[b].push_back({ a, c });
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> que;
	que.push({ 1, 0 });

	int maxVal = 0;
	while (!que.empty()) {
		int ep = que.top().first;
		int cost = que.top().second;
		que.pop();

		if (Visited[ep]) continue;
		Visited[ep] = true;
		Ans += cost;
		maxVal = max(maxVal, cost);

		for (auto path : Path[ep]) {
			if (Visited[path.first]) continue;
			que.push({ path.first, path.second });
		}
	}

	cout << Ans - maxVal;

	return 0;
}