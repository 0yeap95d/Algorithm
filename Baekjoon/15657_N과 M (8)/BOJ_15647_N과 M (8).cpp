#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> Arr, Ans;

void DFS(int idx) {
	if (idx >= M) {
		for (int i = 0; i < M; i++)
			cout << Ans[i] << " ";
		cout << "\n";
		return;
	}

	for (int n : Arr) {
		if (idx != 0 && Ans[idx - 1] > n) continue;
		Ans[idx] = n;
		DFS(idx + 1);
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

	DFS(0);

	return 0;
}