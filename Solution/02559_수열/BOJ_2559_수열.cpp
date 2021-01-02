#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// 온도를 측정한 날짜의 수 N, 연속적인 날짜의 수 K
	int N, K;
	cin >> N >> K;

	// 날짜별 온도 입력, 누적 합
	vector<int> temp;
	temp.assign(N + 1, 0);
	for (int i = 1; i <= N; i++) {
		cin >> temp[i];
		temp[i] += temp[i - 1];
	}

	// 최대합 구하기
	int ans = -987654321;
	for (int i = K; i <= N; i++) ans = max(ans, temp[i] - temp[i - K]);
	
	// 정답 출력
	cout << ans;

	return 0;
}