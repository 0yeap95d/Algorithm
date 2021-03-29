#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// �� ����ũ ���� �Է�
	int L = 0;
	cin >> L;
	vector<int> cake(L + 1, 0);

	// ������ ��
	int N = 0;
	cin >> N;

	// �����ں� �� ����ũ �޴� ����
	int P, K;
	int val1, val2, ans1, ans2;
	val1 = val2 = ans1 = ans2 = 0;
	for (int i = 1; i < N + 1; i++) {
		cin >> P >> K;
		
		int num = K - P + 1;

		// ���� ���� ������ ���� ������ ����ϰ� �ִ� ��û�� ��ȣ
		if (val1 < num) {
			ans1 = i;
			val1 = num;
		}

		// ���� ����ũ ���� ���������� üũ
		for (int idx = P; idx <= K; idx++) {
			if (cake[idx] == 0) cake[idx] = i;
			else num--;
		}

		// ���� ���� ���� ������ �޴� ��û�� ��ȣ
		if (val2 < num) {
			ans2 = i;
			val2 = num;
		}
	}

	// ��� ���
	cout << ans1 << "\n" << ans2;

	return 0;
}