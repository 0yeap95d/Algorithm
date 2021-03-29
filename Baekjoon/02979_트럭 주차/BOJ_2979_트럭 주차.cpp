#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	// 주차요금 입력
	int fee[4] = { 0, };
	for (int i = 1; i < 4; i++) cin >> fee[i];

	// 트럭 주차시간 입력 (1은 들어온 시간, -1은 나가는 시간)
	pair<int, int> time[6];
	for (int i = 0; i < 6; i += 2) {
		cin >> time[i].first >> time[i + 1].first;
		time[i].second = 1;
		time[i + 1].second = -1;
	}

	// 정렬
	sort(time, time + 6);

	// 주차 요금 계산
	int cnt, pre, ans;
	cnt = pre = ans = 0;
	for (int i = 0; i < 6; i++) {
		ans += (time[i].first - pre) * fee[cnt] * cnt;
		pre = time[i].first;
		if (time[i].second == 1) cnt++;
		else cnt--;
	}

	// 정답 출력
	cout << ans;

	return 0;
}