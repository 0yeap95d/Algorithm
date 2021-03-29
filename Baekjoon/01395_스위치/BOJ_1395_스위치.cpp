#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, M;
vector<int> SegmentTree;
vector<bool> Lazy;

void Setting_SegmentTree() {
	int Tree_Height = (int)ceil(log2(N));
	int Tree_Size = (1 << (Tree_Height + 1));
	SegmentTree.resize(Tree_Size);
	Lazy.resize(Tree_Size);
}

void Lazy_Update(int Node, int Start, int End) {
	if (!Lazy[Node]) return;

	SegmentTree[Node] = (End - Start + 1) - SegmentTree[Node];
	if (Start != End) {
		Lazy[Node * 2] = !Lazy[Node * 2];
		Lazy[Node * 2 + 1] = !Lazy[Node * 2 + 1];
	}
	Lazy[Node] = false;
}

void Update(int Node, int Start, int End, int Left, int Right) {

	Lazy_Update(Node, Start, End);

	if (Right < Start || End < Left) return;
	if (Left <= Start && End <= Right) {
		SegmentTree[Node] = (End - Start + 1) - SegmentTree[Node];
		if (Start != End) {
			Lazy[Node * 2] = !Lazy[Node * 2];
			Lazy[Node * 2 + 1] = !Lazy[Node * 2 + 1];
		}
		return;
	}

	int Mid = (Start + End) / 2;
	Update(Node * 2, Start, Mid, Left, Right);
	Update(Node * 2 + 1, Mid + 1, End, Left, Right);
	SegmentTree[Node] = SegmentTree[Node * 2] + SegmentTree[Node * 2 + 1];
}

int Query(int Node, int Start, int End, int Left, int Right) {

	Lazy_Update(Node, Start, End);

	if (Right < Start || End < Left) return 0;
	if (Left <= Start && End <= Right) return SegmentTree[Node];

	int Mid = (Start + End) / 2;
	int Left_Result = Query(Node * 2, Start, Mid, Left, Right);
	int Right_Result = Query(Node * 2 + 1, Mid + 1, End, Left, Right);
	return Left_Result + Right_Result;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> M;
	Setting_SegmentTree();

	int o, s, t;
	for (int i = 0; i < M; i++) {
		cin >> o >> s >> t;
		if (o == 0) Update(1, 0, N - 1, s - 1, t - 1);
		else cout << Query(1, 0, N - 1, s - 1, t - 1) << "\n";
	}

	return 0;
}