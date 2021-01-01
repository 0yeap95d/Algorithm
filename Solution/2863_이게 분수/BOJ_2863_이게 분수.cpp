#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// A, B, C, D 입력
	double inp[4];
	for (int i = 0; i < 4; i++) cin >> inp[i];

	int ans = 0;
	double maxVal = 0.0;
	for (int i = 0; i < 4; i++) {
		double val = inp[0] / inp[2] + inp[1] / inp[3];
		
		// 최대값 갱신
		if (maxVal < val) {
			ans = i;
			maxVal = val;
		}
		
		// 회전
		double temp = inp[0];
		inp[0] = inp[2];
		inp[2] = inp[3];
		inp[3] = inp[1];
		inp[1] = temp;
	}

	cout << ans;

	return 0;
}