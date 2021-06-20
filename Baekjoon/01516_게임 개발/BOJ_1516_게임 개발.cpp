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
	// N: �ǹ��� ����
	cin >> N;

	// �ð�, �׷��� ũ�� ����
	costs.resize(N + 1);
	needs.resize(N + 1);
	graph.resize(N + 1);
	answer.resize(N + 1);

	// �׷��� �Է�
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

	// �ʱ� �Ǽ� ������ �ǹ� queue�� ����
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

		// �ǹ��� �ϼ��ʿ� ���� �Ǽ��� �� �ִ� �ǹ� queue�� ����
		for (int next : graph[cur]) {
			needs[next]--;
			answer[next] = max(answer[next], costs[next] + cost);
			if (needs[next] == 0) que.push({ next, answer[next] });
		}
	}
}

void print() {	
	// ��� ���
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