#include <iostream>
#include <vector>
using namespace std;

int N, R, Q;
vector<vector<int>> tree;
vector<int> cntVertex;
vector<bool> visited;
vector<int> query;

void init() {
	// N: 트리의 정점의 수, R: 루트의 번호, Q: 쿼리의 수
	cin >> N >> R >> Q;

	// 초기화
	tree.assign(N + 1, vector<int>());
	visited.assign(N + 1, false);
	cntVertex.assign(N + 1, 0);

	// 트리 입력
	int U, V;
	for (int i = 1; i < N; i++) {
		cin >> U >> V;
		tree[U].push_back(V);
		tree[V].push_back(U);
	}

	// 쿼리 입력
	int num;
	for (int i = 0; i < Q; i++) {
		cin >> num;
		query.push_back(num);
	}
}

int dfs(int node) {
	int ret = 0;
	visited[node] = true;	// 방문체크

	// 방문했던 곳이라면 상위 노드이므로 제외
	for (int child : tree[node]) 
		if (!visited[child]) ret += dfs(child); 

	return cntVertex[node] = ret + 1;
}

void print() {
	for (int node : query) 
		cout << cntVertex[node] << '\n';
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	init();
	dfs(R);
	print();

	return 0;
}