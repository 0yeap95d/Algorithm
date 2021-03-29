#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<int> Arr, Ans;

void Permutation(int idx) {

	// ������ M���� ���̸�ŭ ä�������� ���
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

	// �Է�
	cin >> N >> M;
	Arr.resize(N), Ans.resize(M);
	for (int i = 0; i < N; i++) cin >> Arr[i];

	// ����
	sort(Arr.begin(), Arr.end());

	// ���� �����
	Permutation(0);

	return 0;
}