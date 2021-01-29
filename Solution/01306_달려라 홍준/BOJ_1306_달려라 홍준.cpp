#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#define SIZE 1000001
using namespace std;

int N, M;
int Arr[SIZE];
vector<int> SegmentTree;

void Setting_SegmentTree() {
	int tree_height = (int)ceil(log2(N));
	int tree_size = (1 << (tree_height + 1));
	SegmentTree.resize(tree_size);
}

int Make_SegmentTree(int Node, int Start, int End) {
	if (Start == End) return SegmentTree[Node] = Arr[Start];

	int mid = (Start + End) / 2;
	int left = Make_SegmentTree(Node * 2, Start, mid);
	int right = Make_SegmentTree(Node * 2 + 1, mid + 1, End);
	return SegmentTree[Node] = max(left, right);
}

int Query_SegmentTree(int Node, int Start, int End, int Left, int Right) {

	if (Right < Start || End < Left) return 0;
	else if (Left <= Start && End <= Right) return SegmentTree[Node];

	int mid = (Start + End) / 2;
	int left = Query_SegmentTree(Node * 2, Start, mid, Left, Right);
	int right = Query_SegmentTree(Node * 2 + 1, mid + 1, End, Left, Right);
	return max(left, right);
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> Arr[i];

	Setting_SegmentTree();
	Make_SegmentTree(1, 0, N - 1);

	for (int i = M - 1; i <= N - M; i++) {
		cout << Query_SegmentTree(1, 0, N - 1, i - M + 1, i + M - 1) << "\n";
	}
	

	return 0;
}