#include <iostream>
#define MAX 10001
using namespace std;

int testcase;
int N, x, y;
int height[MAX], parents[MAX];

void init() {

	for (int i = 0; i < MAX; i++) {
		height[i] = parents[i] = 0;
	}

	cin >> N;
	int p, c;
	for (int i = 0; i < N - 1; i++) {
		cin >> p >> c;
		parents[c] = p;
	}
	cin >> x >> y;
}

int setHeight(int node) {
	if (parents[node] == 0) return height[node] = 1;	// root node�� ���
	if (height[node] != 0) return height[node];			// node�� ���̰� ����Ǿ��ִ� ���
	return height[node] = setHeight(parents[node]) + 1;	// ���� �湮�� node�� ���
}

int findLCA() {
	setHeight(x);
	setHeight(y);

	while (height[x] > height[y]) x = parents[x];
	while (height[x] < height[y]) y = parents[y];
	while (x != y) {
		x = parents[x];
		y = parents[y];
	}

	return x;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> testcase;

	while (testcase--) {
		init();
		cout << findLCA() << '\n';
	}

	return 0;
}