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
	// N: 도미노 개수, M: 관계의 개수
	cin >> N >> M;

	// 초기화
	id = cntSCC = 0;
	graph.assign(N + 1, vector<int>());
	nodeId.assign(N + 1, 0);
	finished.assign(N + 1, false);
	SCC.assign(N + 1, 0);

	// 그래프 입력
	int start, end;
	for (int i = 0; i < M; i++) {
		cin >> start >> end;
		graph[start].push_back(end);
	}
}

int dfs(int node) {
	nodeId[node] = ++id;	// 고유번호 부여
	path.push(node);		// 스택에 경로 저장

	int parentId = nodeId[node];
	for (int nextNode : graph[node]) {
		// 다음 node가 한번도 방문하지 않은 경우
		if (nodeId[nextNode] == 0) parentId = min(parentId, dfs(nextNode));
		
		// 다음 node를 이미 지나온 경우 (스택에 존재하는 경우)
		else if (!finished[nextNode]) parentId = min(parentId, nodeId[nextNode]);

		// 이미 처리가 끝난 노드(스택에 존재하지 않는 경우)는 신경쓰지 않는다
	}

	// 자기 자신으로 돌아온 경우
	if (parentId == nodeId[node]) {
		cntSCC++;	// scc 개수 증가
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
			indegree[SCC[ep]]++;	// 같은 SCC가 아닐때 indegree 증가
		}
	}

	for (int val : indegree) if (val == 0) res++;	// indegree가 0인 node 카운트
	
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