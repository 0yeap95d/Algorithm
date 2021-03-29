#include <iostream>
#include <algorithm>
#define COL_SIZE 11
#define ROW_SIZE 31
#define INF 987654321
using namespace std;

int N, M, H, Ans;
int Ladder[ROW_SIZE][COL_SIZE];

// ��ٸ� ���� �Է�
void Setting_Ladder() {
	cin >> N >> M >> H;

	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		Ladder[a][b] = 1;
		Ladder[a][b + 1] = -1;
	}

	Ans = INF;
}

// ��ٸ��� �ڱ� ��ġ�� ���ƿ����� Ȯ��
bool isCorrect() {
	for (int c = 1; c <= N; c++) {
		int pos = c;
		for (int r = 1; r <= H; r++) pos += Ladder[r][pos];
		if (pos != c) return false;
	}
	return true;
}

void Update_Ladder(int line, int sum) {

	// Ans ���� �� ���� ��ٸ��� �߰��� �� ����
	if (Ans <= sum || 3 < sum) return;

	// �� �̻� �߰��� ��ٸ��� ���� �� 
	if (isCorrect()) {
		Ans = min(Ans, sum);
		return;
	}

	// ������ ���� �߰�
	for (int i = line; i <= H; i++) {
		for (int j = 1; j < N; j++) {
			if (Ladder[i][j] != 0 || Ladder[i][j + 1] != 0) continue;
			Ladder[i][j] = 1;
			Ladder[i][j + 1] = -1;
			Update_Ladder(i, sum + 1);
			Ladder[i][j] = Ladder[i][j + 1] = 0;
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	Setting_Ladder();
	Update_Ladder(1, 0);

	if (Ans == INF) Ans = -1;
	cout << Ans;

	return 0;
}