#include <iostream>
#include <vector>
using namespace std;

int N, root, delNode;
vector<vector<int>> tree;

void init() {
	// N: 노드의 개수
	cin >> N;

	// 트리 초기화
	tree.assign(N, vector<int>());

	// 트리 입력
	int parent;
	for (int node = 0; node < N; node++) {
		cin >> parent;
		if (parent == -1) root = node;
		else tree[parent].push_back(node);
	}

	// 삭제할 노드 입력
	cin >> delNode;
}

int dfs(int node) {

	int res, cnt;
	res = cnt = 0;

	for (int child : tree[node]) {
		if (child != delNode) {		// 삭제된 노드인 경우 방문 x
			res += dfs(child);
			cnt++;
		}
	}

	if (cnt == 0) return 1;
	return res;
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	init();
	if (root == delNode) cout << 0;
	else cout << dfs(root);

	return 0;
}