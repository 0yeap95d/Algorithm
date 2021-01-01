#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// 버섯 입력, 누적 합
	vector<int> inp(11, 0);
	for (int i = 1; i <= 10; i++) {
		cin >> inp[i];
		inp[i] += inp[i - 1];
	}

	// 100과 차이가 최소인 값 구하기
	int ans, gap = 101;
	for (int i = 1; i <= 10; i++) {
		if (gap >= abs(inp[i] - 100)) {
			ans = inp[i];
			gap = abs(inp[i] - 100);
		}
		else break;
	}

	// 정답 출력
	cout << ans;

	return 0;
}