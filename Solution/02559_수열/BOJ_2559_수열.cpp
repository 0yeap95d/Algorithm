#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// �µ��� ������ ��¥�� �� N, �������� ��¥�� �� K
	int N, K;
	cin >> N >> K;

	// ��¥�� �µ� �Է�, ���� ��
	vector<int> temp;
	temp.assign(N + 1, 0);
	for (int i = 1; i <= N; i++) {
		cin >> temp[i];
		temp[i] += temp[i - 1];
	}

	// �ִ��� ���ϱ�
	int ans = -987654321;
	for (int i = K; i <= N; i++) ans = max(ans, temp[i] - temp[i - K]);
	
	// ���� ���
	cout << ans;

	return 0;
}