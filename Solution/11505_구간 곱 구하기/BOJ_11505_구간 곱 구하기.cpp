#include <iostream>
#include <cmath>
#include <vector>
#define SIZE 1000001
#define MOD 1000000007
typedef long long ll;
using namespace std;

int N, M, K;
int Arr[SIZE];
vector<ll> SegmentTree;

void Setting_SegmentTree() {
	int Tree_Height = (int)ceil(log2(N));
	int Tree_Size = (1 << (Tree_Height + 1));
	SegmentTree.resize(Tree_Size);
}

ll Make_SegmentTree(int Node, int Start, int End) {
	if (Start == End) return SegmentTree[Node] = Arr[Start] % MOD;

	int Mid = (Start + End) / 2;
	ll Left_Result = Make_SegmentTree(Node * 2, Start, Mid);
	ll Right_Result = Make_SegmentTree(Node * 2 + 1, Mid + 1, End);
	return SegmentTree[Node] = (Left_Result * Right_Result) % MOD;
}

ll Update_SegmentTree(int Node, int Start, int End, int Left, int Right, ll Value) {
	if (Right < Start || End < Left) return SegmentTree[Node];
	if (Left <= Start && End <= Right) return SegmentTree[Node] = Value;
	
	int Mid = (Start + End) / 2;
	ll Left_Result = Update_SegmentTree(Node * 2, Start, Mid, Left, Right, Value);
	ll Right_Result = Update_SegmentTree(Node * 2 + 1, Mid + 1, End, Left, Right, Value);
	return SegmentTree[Node] = (Left_Result * Right_Result) % MOD;
}

ll Query_SegmentTree(int Node, int Start, int End, int Left, int Right) {
	if (Right < Start || End < Left) return 1;
	if (Left <= Start && End <= Right) return SegmentTree[Node];

	int Mid = (Start + End) / 2;
	ll Left_Result = Query_SegmentTree(Node * 2, Start, Mid, Left, Right);
	ll Right_Result = Query_SegmentTree(Node * 2 + 1, Mid + 1, End, Left, Right);
	return (Left_Result * Right_Result) % MOD;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) cin >> Arr[i];
	
	Setting_SegmentTree();
	Make_SegmentTree(1, 0, N - 1);

	int a, b, c;
	for (int i = 0; i < M + K; i++) {
		cin >> a >> b >> c;
		if (a == 1) Update_SegmentTree(1, 0, N - 1, b - 1, b - 1, c);
		else cout << Query_SegmentTree(1, 0, N - 1, b - 1, c - 1) % MOD << "\n";
	}

	return 0;
}