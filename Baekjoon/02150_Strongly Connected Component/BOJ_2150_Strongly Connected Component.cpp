#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define MAX 10001
using namespace std;

int V, E, id;
int nodeId[MAX];
bool finished[MAX];
vector<int> adjList[MAX];
vector<vector<int>> SCC;
stack<int> st;

void init() {

	// V: ������ ����, E: ������ ����
	cin >> V >> E;
	
	// �׷��� �Է�
	int v1, v2;
	for (int i = 0; i < E; i++) {
		cin >> v1 >> v2;
		adjList[v1].push_back(v2);
	}
}

// ������ ������ŭ DFS ����
int dfs(int v) {
	nodeId[v] = ++id;
	st.push(v);	// ���ÿ� �ڱ� �ڽ� ����

	int parent = nodeId[v];
	for (int i = 0; i < adjList[v].size(); i++) {
		int nv = adjList[v][i];

		// �湮���� ���� �̿�
		if (nodeId[nv] == 0) parent = min(parent, dfs(nv));

		// ó�� ���� �̿�
		else if (!finished[nv]) parent = min(parent, nodeId[nv]);
	}

	// �θ��尡 �ڱ� �ڽ��� ���
	if (parent == nodeId[v]) {
		vector<int> scc;
		while (1) {
			int tv = st.top();
			st.pop();
			scc.push_back(tv);
			finished[tv] = true;
			if (tv == v) break;
		}
		sort(scc.begin(), scc.end());
		SCC.push_back(scc);
	}

	// �ڽ��� �θ� ���� ��ȯ
	return parent;
}

void print() {
	cout << SCC.size() << '\n';
	for (auto scc : SCC) {
		for (auto v : scc) {
			cout << v << ' ';
		}
		cout << -1 << '\n';
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	init();
	for (int i = 1; i <= V; i++) 
		if (nodeId[i] == 0) dfs(i);
	sort(SCC.begin(), SCC.end());
	print();

	return 0;
}