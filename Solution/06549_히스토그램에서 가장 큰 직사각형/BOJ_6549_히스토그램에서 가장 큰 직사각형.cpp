#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

#define SIZE 100001
#define INF 987654321

typedef long long ll;
using namespace std;

int N;
int Arr[SIZE];
vector<int> SegmentTree;

void Setting_SegmentTree() {
	int Tree_Height = (int)ceil(log2(N));
	int Tree_Size = (1 << (Tree_Height + 1));
	SegmentTree.resize(Tree_Size);
}

int Make_SegmentTree(int Node, int Start, int End) {
	if (Start == End) return SegmentTree[Node] = Start;
	int Mid = (Start + End) / 2;
	int Left_Idx = Make_SegmentTree(Node * 2, Start, Mid);
	int Right_Idx = Make_SegmentTree(Node * 2 + 1, Mid + 1, End);
	return SegmentTree[Node] = Arr[Left_Idx] < Arr[Right_Idx] ? Left_Idx : Right_Idx;
}

int Query_SegmentTree(int Node, int Start, int End, int Left, int Right) {
	
	if (Right < Start || End < Left) return INF;

	if (Left <= Start && End <= Right) return SegmentTree[Node];

	int Mid = (Start + End) / 2;
	int Left_Idx = Query_SegmentTree(Node * 2, Start, Mid, Left, Right);
	int Right_Idx = Query_SegmentTree(Node * 2 + 1, Mid + 1, End, Left, Right);

	if (Left_Idx == INF) return Right_Idx;
	else if (Right_Idx == INF) return Left_Idx;
	return Arr[Left_Idx] < Arr[Right_Idx] ? Left_Idx : Right_Idx;
}

ll getMaxArea(int Left, int Right) {
	int Min_Idx = Query_SegmentTree(1, 0, N - 1, Left, Right);
	ll Area = (ll)(Right - Left + 1) * (ll)Arr[Min_Idx];
	
	if (Left <= Min_Idx - 1) Area = max(Area, getMaxArea(Left, Min_Idx - 1));
	if (Min_Idx + 1 <= Right) Area = max(Area, getMaxArea(Min_Idx + 1, Right));
	
	return Area;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	while (cin >> N) {
		if (N == 0) break;
		for (int i = 0; i < N; i++) cin >> Arr[i];
		Setting_SegmentTree();
		Make_SegmentTree(1, 0, N - 1);
		cout << getMaxArea(0, N - 1) << "\n";
	}

	return 0;
}