#include <iostream>
#include <vector>
using namespace std;

int N, R, Q;
vector<vector<int>> tree;
vector<int> cntVertex;
vector<bool> visited;
vector<int> query;

void init() {
	// N: Ʈ���� ������ ��, R: ��Ʈ�� ��ȣ, Q: ������ ��
	cin >> N >> R >> Q;

	// �ʱ�ȭ
	tree.assign(N + 1, vector<int>());
	visited.assign(N + 1, false);
	cntVertex.assign(N + 1, 0);

	// Ʈ�� �Է�
	int U, V;
	for (int i = 1; i < N; i++) {
		cin >> U >> V;
		tree[U].push_back(V);
		tree[V].push_back(U);
	}

	// ���� �Է�
	int num;
	for (int i = 0; i < Q; i++) {
		cin >> num;
		query.push_back(num);
	}
}

int dfs(int node) {
	int ret = 0;
	visited[node] = true;	// �湮üũ

	// �湮�ߴ� ���̶�� ���� ����̹Ƿ� ����
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