#include <iostream>
#define SIZE 1001
using namespace std;

int N;
int CountEdge[SIZE];
int Graph[SIZE][SIZE];

bool IsPossible() {
	for (int i = 0; i < N; i++) {
		if (CountEdge[i] % 2 != 0) return false;
	}
	return true;
}

void DFS(int idx) {
	for (int i = 0; i < N; i++) {
		while (Graph[idx][i] > 0) {
			Graph[idx][i]--, Graph[i][idx]--;
			DFS(i);
		}
	}
	cout << idx + 1 << " ";
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N;

	// �׷��� �Է�
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Graph[i][j];
			CountEdge[i] = CountEdge[i] + Graph[i][j];
		}
	}

	// �Ұ����� ���
	if (!IsPossible()) {
		cout << -1;
		return 0;
	}

	// DFS
	DFS(0);

	return 0;
}