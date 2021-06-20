#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
vector<int> costs;
vector<int> needs;
vector<vector<int>> graph;
vector<int> answer;

void init() {
	// N: 건물의 종류
	cin >> N;

	// 시간, 그래프 크기 설정
	costs.resize(N + 1);
	needs.resize(N + 1);
	graph.resize(N + 1);
	answer.resize(N + 1);

	// 그래프 입력
	for (int i = 1; i <= N; i++) {
		cin >> costs[i];
		int node;
		while (1) {
			cin >> node;
			if (node == -1) break;
			needs[i]++;
			graph[node].push_back(i);
		}
	}
}

void topologicalSort() {
	queue<pair<int, int>> que;

	// 초기 건설 가능한 건물 queue에 삽입
	for (int i = 1; i <= N; i++) {
		if (needs[i] == 0) {
			que.push({ i, costs[i] });
			answer[i] = costs[i];
		}
	}

	while (!que.empty()) {
		int cur = que.front().first;
		int cost = que.front().second;
		que.pop();

		// 건물이 완성됨에 따라 건설할 수 있는 건물 queue에 삽입
		for (int next : graph[cur]) {
			needs[next]--;
			answer[next] = max(answer[next], costs[next] + cost);
			if (needs[next] == 0) que.push({ next, answer[next] });
		}
	}
}

void print() {	
	// 결과 출력
	for (int i = 1; i <= N; i++)
		cout << answer[i] << '\n';
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	init();
	topologicalSort();
	print();

	return 0;
}