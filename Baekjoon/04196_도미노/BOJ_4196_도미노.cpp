#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int TC, N, M, id, cntSCC;
vector<vector<int>> graph;
vector<int> nodeId;
stack<int> path;
vector<bool> finished;
vector<int> SCC;

void init() {
	// N: ���̳� ����, M: ������ ����
	cin >> N >> M;

	// �ʱ�ȭ
	id = cntSCC = 0;
	graph.assign(N + 1, vector<int>());
	nodeId.assign(N + 1, 0);
	finished.assign(N + 1, false);
	SCC.assign(N + 1, 0);

	// �׷��� �Է�
	int start, end;
	for (int i = 0; i < M; i++) {
		cin >> start >> end;
		graph[start].push_back(end);
	}
}

int dfs(int node) {
	nodeId[node] = ++id;	// ������ȣ �ο�
	path.push(node);		// ���ÿ� ��� ����

	int parentId = nodeId[node];
	for (int nextNode : graph[node]) {
		// ���� node�� �ѹ��� �湮���� ���� ���
		if (nodeId[nextNode] == 0) parentId = min(parentId, dfs(nextNode));
		
		// ���� node�� �̹� ������ ��� (���ÿ� �����ϴ� ���)
		else if (!finished[nextNode]) parentId = min(parentId, nodeId[nextNode]);

		// �̹� ó���� ���� ���(���ÿ� �������� �ʴ� ���)�� �Ű澲�� �ʴ´�
	}

	// �ڱ� �ڽ����� ���ƿ� ���
	if (parentId == nodeId[node]) {
		cntSCC++;	// scc ���� ����
		while (1) {
			int topNode = path.top();
			path.pop();
			finished[topNode] = true;
			SCC[topNode] = cntSCC;
			if (topNode == node) break;
		}
	}

	return parentId;
}

int countZeroIndegree() {
	int res = -1;
	vector<int> indegree(cntSCC + 1, 0);

	for (int sp = 1; sp <= N; sp++) {
		for (int ep : graph[sp]) {
			if (SCC[sp] == SCC[ep]) continue;
			indegree[SCC[ep]]++;	// ���� SCC�� �ƴҶ� indegree ����
		}
	}

	for (int val : indegree) if (val == 0) res++;	// indegree�� 0�� node ī��Ʈ
	
	return res;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> TC;
	while (TC--) {
		init();
		for (int i = 1; i <= N; i++) 
			if (nodeId[i] == 0) dfs(i);
		cout << countZeroIndegree() << '\n';
	}

	return 0;
}