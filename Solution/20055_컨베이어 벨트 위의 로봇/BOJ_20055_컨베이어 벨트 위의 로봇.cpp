#include <iostream>
#define SIZE 202
using namespace std;

int N, K, ans;
int weight[SIZE];
bool robot[SIZE];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// �����̾� ��Ʈ ���� N, ������ ���� K
	cin >> N >> K;

	// ��Ʈ ������ �Է�
	for (int i = 1; i <= N * 2; i++) cin >> weight[i];

	int cnt = 0;
	while (cnt < K) {
		ans++;

		// ��Ʈ�� ȸ���Ѵ�
		weight[0] = weight[N * 2];
		robot[N] = false;
		for (int i = N * 2; i > 0; i--) {
			weight[i] = weight[i - 1];
			if (i <= N) robot[i] = robot[i - 1];
		}

		// �κ��� �̵��Ѵ�
		robot[N] = false;
		for (int i = N; i > 0; i--) {
			if (robot[i] || !robot[i - 1] || weight[i] == 0) continue;
			robot[i] = robot[i - 1];
			robot[i - 1] = false;
			weight[i]--;
			if (weight[i] == 0) cnt++;
		}

		// �κ��� �ø���
		if (weight[1] != 0 && !robot[1]) {
			robot[1] = true;
			weight[1]--;
			if (weight[1] == 0) cnt++;
		}
	}

	// ���� ���
	cout << ans;

	return 0;
}