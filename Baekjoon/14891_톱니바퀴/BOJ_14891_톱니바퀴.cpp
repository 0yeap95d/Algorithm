#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int K;
bool gear[4][8];

void Rotation(int n, int d, int pre) {

	// ù��° ��Ϲ����� �ƴϸ� ���� Ȯ�� �� ȸ��
	if (n != 0 && n - 1 != pre && gear[n][6] != gear[n - 1][2]) {
		Rotation(n - 1, -d, n);
	}

	// ������ ��Ϲ����� �ƴϸ� ������ Ȯ�� �� ȸ��
	if (n != 3 && n + 1 != pre && gear[n][2] != gear[n + 1][6]) {
		Rotation(n + 1, -d, n);
	}

	// �ð���� ȸ��
	if (d == 1) {
		int temp = gear[n][7];
		for (int i = 7; i >= 1; i--) {
			gear[n][i] = gear[n][i - 1];
		}
		gear[n][0] = temp;
	}

	// �ݽð���� ȸ��
	else {
		int temp = gear[n][0];
		for (int i = 0; i < 7; i++) {
			gear[n][i] = gear[n][i + 1];
		}
		gear[n][7] = temp;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// ����Է�
	string inp;
	for (int i = 0; i < 4; i++) {
		cin >> inp;
		for (int j = 0; j < 8; j++) {
			gear[i][j] = inp[j] - '0';
		}
	}

	// ȸ�� Ƚ�� K �Է�
	cin >> K;

	// ��� ȸ��
	int num, dir;
	for (int i = 0; i < K; i++) {
		cin >> num >> dir;
		Rotation(num - 1, dir, num - 1);
	}

	// ���� ���
	int ans = 0;
	for (int i = 0; i < 4; i++) {
		if (gear[i][0]) ans += pow(2, i);
	}

	// ���� ���
	cout << ans;

	return 0;
}