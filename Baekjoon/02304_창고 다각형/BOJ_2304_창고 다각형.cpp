#include <iostream>
#include <vector>
#include <algorithm>
#define pii pair<int, int>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N;
	cin >> N;

	// ��� ��ġ, ���� �Է�
	int pos, height;
	vector<pii> bar;
	for (int i = 0; i < N; i++) {
		cin >> pos >> height;
		bar.push_back(pii(pos, height));
	}

	sort(bar.begin(), bar.end());

	// ���� ���� ��� ã��
	pii maxVal(0, 0);
	for (int i = 0; i < N; i++) {
		if (maxVal.second < bar[i].second) maxVal = bar[i];
	}

	int ans = maxVal.second;

	// ���ʿ������� ���� ���� ��ձ���
	pii pre(0, 0);
	for (int i = 0; i < N; i++) {
		if (pre.second <= bar[i].second) {
			ans += pre.second * (bar[i].first - pre.first);
			pre = bar[i];
		}
		if (bar[i].first == maxVal.first) break;
	}

	// �����ʿ������� ���� ���� ��ձ���
	pre = pii(0, 0);
	for (int i = N - 1; i >= 0; i--) {
		if (pre.second <= bar[i].second) {
			ans += pre.second * (pre.first - bar[i].first);
			pre = bar[i];
		}
		if (bar[i].first == maxVal.first) break;
	}

	cout << ans;

	return 0;
}