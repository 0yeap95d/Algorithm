#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#define INF 987654321
using namespace std;

struct cmp {
	bool operator()(pair<int, int> p1, pair<int, int> p2) {
		return p1.second > p2.second;
	}
};

int n, m, sp, ep;
vector<vector<pair<int, int>>> graph;
vector<int> path;
vector<int> dist;

void init() {
	cin >> n >> m;
	graph.assign(n + 1, vector<pair<int, int>>());
	dist.assign(n + 1, INF);
	path.assign(n + 1, -1);

	while (m--) {
		int v1, v2, cost;
		cin >> v1 >> v2 >> cost;
		graph[v1].push_back({ v2, cost });
	}

	cin >> sp >> ep;
}

void dijkstra() {
	priority_queue<pair<int ,int>, vector<pair<int, int>>, cmp> pq;
	pq.push({ sp, 0 });
	dist[sp] = 0;

	while (!pq.empty()) {
		int curIdx = pq.top().first;
		int curCost = pq.top().second;
		pq.pop();

		for (int i = 0; i < graph[curIdx].size(); i++) {
			int nextIdx = graph[curIdx][i].first;
			int nextCost = graph[curIdx][i].second + curCost;
			
			if (dist[nextIdx] > nextCost) {
				path[nextIdx] = curIdx;
				dist[nextIdx] = nextCost;
				pq.push({ nextIdx, nextCost });
			}
		}
	}
}

void print() {
	stack<int> revPath;
	int idx = ep;
	while (idx > 0) {
		revPath.push(idx);
		idx = path[idx];
	}

	cout << dist[ep] << "\n";
	cout << revPath.size() << "\n";
	while (!revPath.empty()) {
		cout << revPath.top() << " "; 
		revPath.pop();
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	init();
	dijkstra();
	print();

	return 0;
}