#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int N, M;
vector<int> Arr, Ans;
unordered_map<int, int> CntNum;

void DFS(int idx) {
	if (idx >= M) {
		for (int ans : Ans) cout << ans << " ";
		cout << "\n";
		return;
	}

	int pre = 0;
	for (int arr : Arr) {
		if (pre == arr || CntNum[arr] == 0) continue;
		Ans[idx] = pre = arr;
		CntNum[arr]--;
		DFS(idx + 1);
		CntNum[arr]++;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> M;
	Arr.resize(N);
	Ans.resize(M);
	for (int i = 0; i < N; i++) {
		cin >> Arr[i];
		CntNum[Arr[i]]++;
	}
	
	sort(Arr.begin(), Arr.end());

	DFS(0);

	return 0;
}