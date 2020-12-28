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

	// 기둥 위치, 높이 입력
	int pos, height;
	vector<pii> bar;
	for (int i = 0; i < N; i++) {
		cin >> pos >> height;
		bar.push_back(pii(pos, height));
	}

	sort(bar.begin(), bar.end());

	// 가장 높은 기둥 찾기
	pii maxVal(0, 0);
	for (int i = 0; i < N; i++) {
		if (maxVal.second < bar[i].second) maxVal = bar[i];
	}

	int ans = maxVal.second;

	// 왼쪽에서부터 제일 높은 기둥까지
	pii pre(0, 0);
	for (int i = 0; i < N; i++) {
		if (pre.second <= bar[i].second) {
			ans += pre.second * (bar[i].first - pre.first);
			pre = bar[i];
		}
		if (bar[i].first == maxVal.first) break;
	}

	// 오른쪽에서부터 제일 높은 기둥까지
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