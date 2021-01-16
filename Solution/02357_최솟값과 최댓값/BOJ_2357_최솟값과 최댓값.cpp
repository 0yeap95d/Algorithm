#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#define SIZE 100001
#define INF 1000000001
#define ll long long
using namespace std;

int N, M;
int inp[SIZE];
vector<pair<ll, ll>> SegmentTree;

void Setting_SegmentTree() {
	int Tree_Height = (int)ceil(log2(N));
	int Tree_Size = (1 << (Tree_Height + 1));
	SegmentTree.resize(Tree_Size);
}

pair<ll, ll> Make_SegmentTree(int Node, int Start, int End) {
	
	if (Start == End) return SegmentTree[Node] = { inp[Start], inp[Start] };
	
	int Mid = (Start + End) / 2;
	pair<ll, ll> Left_Result = Make_SegmentTree(Node * 2, Start, Mid);
	pair<ll, ll> Right_Result = Make_SegmentTree(Node * 2 + 1, Mid + 1, End);
	return SegmentTree[Node] = { min(Left_Result.first, Right_Result.first), max(Left_Result.second, Right_Result.second) };
}

pair<ll, ll> Query(int Node, int Start, int End, int Left, int Right) {

	if (Right < Start || End < Left) return { INF, 0 };
	if (Left <= Start && End <= Right) return SegmentTree[Node];

	int Mid = (Start + End) / 2;
	pair<ll, ll> Left_Result = Query(Node * 2, Start, Mid, Left, Right);
	pair<ll, ll> Right_Result = Query(Node * 2 + 1, Mid + 1, End, Left, Right);

	return { min(Left_Result.first, Right_Result.first), max(Left_Result.second, Right_Result.second) };
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> inp[i];
	
	Setting_SegmentTree();
	Make_SegmentTree(1, 0, N - 1);

	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		pair<ll, ll> ans = Query(1, 0, N - 1, a - 1, b - 1);
		cout << ans.first << " " << ans.second << "\n";
	}

	return 0;
}