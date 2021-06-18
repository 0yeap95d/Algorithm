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

	// V: 정점의 개수, E: 간선의 개수
	cin >> V >> E;
	
	// 그래프 입력
	int v1, v2;
	for (int i = 0; i < E; i++) {
		cin >> v1 >> v2;
		adjList[v1].push_back(v2);
	}
}

// 정점의 개수만큼 DFS 실행
int dfs(int v) {
	nodeId[v] = ++id;
	st.push(v);	// 스택에 자기 자신 삽입

	int parent = nodeId[v];
	for (int i = 0; i < adjList[v].size(); i++) {
		int nv = adjList[v][i];

		// 방문하지 않은 이웃
		if (nodeId[nv] == 0) parent = min(parent, dfs(nv));

		// 처리 중인 이웃
		else if (!finished[nv]) parent = min(parent, nodeId[nv]);
	}

	// 부모노드가 자기 자신인 경우
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

	// 자신의 부모 값을 반환
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