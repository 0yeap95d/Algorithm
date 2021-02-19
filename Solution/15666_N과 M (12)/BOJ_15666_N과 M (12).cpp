#include <iostream>
#include <vector>
#include <algorithm>
#define SIZE 10001
using namespace std;

int N, M;
bool Check[SIZE];
vector<int> Arr, Ans;

void DFS(int idx, int pos) {
	if (idx >= M) {
		for (int ans : Ans) cout << ans << " ";
		cout << "\n";
		return;
	}

	for (int i = pos; i < Arr.size(); i++) {
		Ans[idx] = Arr[i];
		DFS(idx + 1, i);
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> M;
	int inp;
	for (int i = 0; i < N; i++) {
		cin >> inp;
		if (Check[inp]) continue;
		Check[inp] = true;
		Arr.push_back(inp);
	}

	sort(Arr.begin(), Arr.end());

	Ans.resize(M);
	DFS(0, 0);

	return 0;
}