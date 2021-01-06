#include <iostream>
#include <queue>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// ������ ���� N �Է�
	int N;
	cin >> N;

	// �켱���� ť
	priority_queue<int> pq;
	int inp, ans;

	for (int i = 0; i < N; i++) {
		// ���� �Է�
		cin >> inp;
	
		// �Է��� 0 �϶�
		if (inp == 0) {
			// ť�� ��������� 0, �ƴϸ� ���� ���� �� ���
			ans = 0;
			if (!pq.empty()) {
				ans = -pq.top();
				pq.pop();
			}
			cout << ans << "\n";
		}

		// �Է��� 0�� �ƴ� �� ť ����
		else pq.push(-inp);
	}

	return 0;
}