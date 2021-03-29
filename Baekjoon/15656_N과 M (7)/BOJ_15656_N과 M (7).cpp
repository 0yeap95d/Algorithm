#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<int> Arr, Ans;

void Permutation(int idx) {

	// 순열이 M개의 길이만큼 채워졌을때 출력
	if (idx >= M) {
		for (int i = 0; i < M; i++) cout << Ans[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 0; i < N; i++) {
		Ans[idx] = Arr[i];
		Permutation(idx + 1);
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// 입력
	cin >> N >> M;
	Arr.resize(N), Ans.resize(M);
	for (int i = 0; i < N; i++) cin >> Arr[i];

	// 정렬
	sort(Arr.begin(), Arr.end());

	// 순열 만들기
	Permutation(0);

	return 0;
}