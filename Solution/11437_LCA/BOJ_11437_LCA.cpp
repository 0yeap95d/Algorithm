#include <iostream>
#include <vector>
#define SIZE 50001
using namespace std;

int N, M;
int parents[SIZE];
int depths[SIZE];
vector<int> graph[SIZE];
bool visited[SIZE];

void DFS(int vertex, int depth, int parent) {
	visited[vertex] = true;
	parents[vertex] = parent;
	depths[vertex] = depth;
	for (int v : graph[vertex]) {
		if (!visited[v]) DFS(v, depth + 1, vertex);
	}
}

int LCA(int v1, int v2) {
	int d1 = depths[v1];
	int d2 = depths[v2];

	while (d1 > d2) {
		v1 = parents[v1];
		d1 = depths[v1];
	}

	while (d1 < d2) {
		v2 = parents[v2];
		d2 = depths[v2];
	}

	while (v1 != v2) {
		v1 = parents[v1];
		v2 = parents[v2];
	}

	return v1;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// 정점의 개수 N
	cin >> N;

	// 그래프 입력
	int v1, v2;
	for (int i = 0; i < N - 1; i++) {
		cin >> v1 >> v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}

	// 부모, 깊이 정보 입력
	DFS(1, 0, 0);

	// LCA 개수 M
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> v1 >> v2;
		cout << LCA(v1, v2) << "\n";
	}

	return 0;
}