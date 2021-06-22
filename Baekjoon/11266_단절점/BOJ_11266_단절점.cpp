#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, id;
vector<vector<int>> graph;
vector<int> discovered;
vector<bool> isCut;
vector<int> answer;

void init() {
	// N: 정점의 개수, M: 간선의 개수
	cin >> N >> M;

	// 초기화
	graph.assign(N + 1, vector<int>());
	discovered.assign(N + 1, 0);
	isCut.assign(N + 1, false);

	// 그래프 입력
	int sp, ep;
	for (int i = 0; i < M; i++) {
		cin >> sp >> ep;
		graph[sp].push_back(ep);
		graph[ep].push_back(sp);
	}
}

int dfs(int node, bool isRoot) {
	
	discovered[node] = ++id;
	int ret = discovered[node];
	int child = 0;

	for (int i = 0; i < graph[node].size(); i++) {
		int nextNode = graph[node][i];
		
		if (!discovered[nextNode]) {
			child++;

			int low = dfs(nextNode, false);
			if (!isRoot && low >= discovered[node])
				isCut[node] = true;
			ret = min(ret, low);
		}
		else ret = min(ret, discovered[nextNode]);
	}

	// 루트노드인 경우 자식이 2이상인 경우 단절점
	if (isRoot) isCut[node] = (child >= 2);
	
	return ret;
}

void setAnswer() {
	for (int i = 1; i <= N; i++) 
		if (isCut[i]) answer.push_back(i);
	sort(answer.begin(), answer.end());
}

void print() {
	cout << answer.size() << '\n';
	for (int ans : answer) cout << ans << ' ';
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	init();
	for (int i = 1; i <= N; i++) 
		if (!discovered[i]) dfs(i, true);
	setAnswer();
	print();

	return 0;
}