#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int K;
bool gear[4][8];

void Rotation(int n, int d, int pre) {

	// 첫번째 톱니바퀴가 아니면 왼쪽 확인 후 회전
	if (n != 0 && n - 1 != pre && gear[n][6] != gear[n - 1][2]) {
		Rotation(n - 1, -d, n);
	}

	// 마지막 톱니바퀴가 아니면 오른쪽 확인 후 회전
	if (n != 3 && n + 1 != pre && gear[n][2] != gear[n + 1][6]) {
		Rotation(n + 1, -d, n);
	}

	// 시계방향 회전
	if (d == 1) {
		int temp = gear[n][7];
		for (int i = 7; i >= 1; i--) {
			gear[n][i] = gear[n][i - 1];
		}
		gear[n][0] = temp;
	}

	// 반시계방향 회전
	else {
		int temp = gear[n][0];
		for (int i = 0; i < 7; i++) {
			gear[n][i] = gear[n][i + 1];
		}
		gear[n][7] = temp;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// 톱니입력
	string inp;
	for (int i = 0; i < 4; i++) {
		cin >> inp;
		for (int j = 0; j < 8; j++) {
			gear[i][j] = inp[j] - '0';
		}
	}

	// 회전 횟수 K 입력
	cin >> K;

	// 톱니 회전
	int num, dir;
	for (int i = 0; i < K; i++) {
		cin >> num >> dir;
		Rotation(num - 1, dir, num - 1);
	}

	// 점수 계산
	int ans = 0;
	for (int i = 0; i < 4; i++) {
		if (gear[i][0]) ans += pow(2, i);
	}

	// 정답 출력
	cout << ans;

	return 0;
}