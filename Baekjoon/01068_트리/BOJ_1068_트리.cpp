#include <iostream>
#include <vector>
using namespace std;

int N, root, delNode;
vector<vector<int>> tree;

void init() {
	// N: ����� ����
	cin >> N;

	// Ʈ�� �ʱ�ȭ
	tree.assign(N, vector<int>());

	// Ʈ�� �Է�
	int parent;
	for (int node = 0; node < N; node++) {
		cin >> parent;
		if (parent == -1) root = node;
		else tree[parent].push_back(node);
	}

	// ������ ��� �Է�
	cin >> delNode;
}

int dfs(int node) {

	int res, cnt;
	res = cnt = 0;

	for (int child : tree[node]) {
		if (child != delNode) {		// ������ ����� ��� �湮 x
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