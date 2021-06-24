#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int V, E, id;
vector<vector<int>> graph;
vector<int> discovered;
vector<pair<int, int>> answer;

void init() {
	// V: ������ ����, E: ������ ����
	cin >> V >> E;

	// �ʱ�ȭ
	graph.assign(V + 1, vector<int>());
	discovered.assign(V + 1, 0);

	// �׷��� �Է�
	int v1, v2;
	for (int i = 0; i < E; i++) {
		cin >> v1 >> v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}
}

int dfs(int node, int parents) {
	discovered[node] = ++id;
	int ret = discovered[node];
	int child = 0;

	for (int nextNode : graph[node]) {
		// �ǵ��ƿ��� ����
		if (nextNode == parents) continue;

		// ���� �湮���� ���� ����
		if (discovered[nextNode] == 0) {
			int low = dfs(nextNode, node);
			if (low > discovered[node])
				answer.push_back({ min(node, nextNode), max(node, nextNode) });
			ret = min(ret, low);
		}

		// �̹� �湮�ߴ� ����
		else ret = min(ret, discovered[nextNode]);
	}

	return ret;
}

void print() {
	cout << answer.size() << '\n';
	for (auto ans : answer) 
		cout << ans.first << ' ' << ans.second << '\n';
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	init();
	for (int i = 1; i <= V; i++) dfs(i, 0);
	sort(answer.begin(), answer.end());
	print();

	return 0;
}