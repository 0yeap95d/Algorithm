#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX_SIZE 51
#define MAX_VAL 987654321
using namespace std;

int ans[MAX_SIZE];
int member[MAX_SIZE][MAX_SIZE];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// ȸ���� �� N
	int N;
	cin >> N;

	// ȸ�� �迭 �ʱ�ȭ (�ִ밪)
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			member[i][j] = (i == j) ? 0 : MAX_VAL;
		}
	}

	// ģ������ ���� �Է�
	int m1, m2;
	while (cin >> m1 >> m2) {
		if (m1 == -1 && m2 == -1) break;
		member[m1][m2] = member[m2][m1] = 1;
	}

	// �÷��̵�-�ͼ� �˰���
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				member[i][j] = min(member[i][j], member[i][k] + member[k][j]);
			}
		}
	}

	// ȸ�� ����
	int minScore = MAX_VAL;
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		int score = 0;
		for (int j = 1; j <= N; j++) score = max(score, member[i][j]);
		ans[i] = score;
		if (minScore == ans[i]) cnt++;
		else if (minScore > ans[i]) {
			minScore = ans[i];
			cnt = 1;
		}
	}

	// ȸ�� �ĺ��� ������ �ĺ��� �� ���
	cout << minScore << " " << cnt << "\n";

	// ȸ�� �ĺ� ���
	for (int i = 0; i < N; i++) {
		if (ans[i] == minScore) cout << i << " ";
	}

	return 0;
}