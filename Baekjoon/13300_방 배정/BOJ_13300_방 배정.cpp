#include <iostream>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	int student[2][7] = { 0, };
	int gender, grade, ans = 0;
	for (int i = 0; i < N; i++) {
		cin >> gender >> grade;
		student[gender][grade]++;
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 1; j <= 6; j++) {
			if (student[i][j] == 0) continue;
			ans += student[i][j] / K;
			if (student[i][j] % K != 0) ans++;
		}
	}

	cout << ans;

	return 0;
}