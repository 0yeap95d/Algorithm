#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> Arr, Ans;

void DFS(int idx, int pos) {
	if (idx >= M) {
		for (int ans : Ans) cout << ans << " ";
		cout << "\n";
		return;
	}

	int pre = 0;
	for (int i = pos; i < N; i++) {
		if (pre == Arr[i]) continue;
		pre = Ans[idx] = Arr[i];
		DFS(idx + 1, i + 1);
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> M;
	Arr.resize(N);
	Ans.resize(M);
	for (int i = 0; i < N; i++) cin >> Arr[i];

	sort(Arr.begin(), Arr.end());

	DFS(0, 0);

	return 0;
}