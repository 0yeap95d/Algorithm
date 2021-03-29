#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	// ������� �Է�
	int fee[4] = { 0, };
	for (int i = 1; i < 4; i++) cin >> fee[i];

	// Ʈ�� �����ð� �Է� (1�� ���� �ð�, -1�� ������ �ð�)
	pair<int, int> time[6];
	for (int i = 0; i < 6; i += 2) {
		cin >> time[i].first >> time[i + 1].first;
		time[i].second = 1;
		time[i + 1].second = -1;
	}

	// ����
	sort(time, time + 6);

	// ���� ��� ���
	int cnt, pre, ans;
	cnt = pre = ans = 0;
	for (int i = 0; i < 6; i++) {
		ans += (time[i].first - pre) * fee[cnt] * cnt;
		pre = time[i].first;
		if (time[i].second == 1) cnt++;
		else cnt--;
	}

	// ���� ���
	cout << ans;

	return 0;
}