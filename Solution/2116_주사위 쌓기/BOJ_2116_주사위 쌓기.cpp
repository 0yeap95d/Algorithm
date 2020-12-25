#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define SIZE 6
using namespace std;

int N, ans;
map<int, int> cross;
vector<vector<int>> inp;

// �ֻ��� ����, ���� ��, ���� ��
void stackDice(int depth, int delVal, int sum) {
	if (depth >= N) {
		ans = max(ans, sum);
		return;
	}

	vector<int> dice(inp[depth].begin(), inp[depth].end());

	// ���� �Ʒ� �� ����
	for (int i = 0; i < SIZE; i++) {
		if (delVal == dice[i]) {
			delVal = dice[cross[i]];
			dice[i] = dice[cross[i]] = 0;
			break;
		}
	}

	// ������ ���� ū �� ����
	int val = 0;
	for (int i = 0; i < SIZE; i++) val = max(val, dice[i]);
	
	// ���� �ֻ����� �̵�
	stackDice(depth + 1, delVal, sum + val);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	inp.assign(N, vector<int>(SIZE, 0));

	// �ֻ��� ���ֺ��� �� ����
	cross[0] = 5;
	cross[1] = 3;
	cross[2] = 4;
	cross[3] = 1;
	cross[4] = 2;
	cross[5] = 0;

	// �ֻ��� �Է¹ޱ�
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < SIZE; j++) cin >> inp[i][j];
	}

	// �ֻ��� �ױ�
	for (int i = 1; i <= SIZE; i++) stackDice(0, i, 0);

	// ���� ���
	cout << ans;

	return 0;
}