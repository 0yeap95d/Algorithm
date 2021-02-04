#include <iostream>
#include <algorithm>
using namespace std;

int dp[3][1000];

int main() {
	int n, out = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> dp[0][i];
		dp[1][i] = 1;
		dp[2][i] = 1;
	}
	for (int i = 0, x = n - 1; i < n; i++, x--) {
		for (int j = 0, y = n - 1; j < i; j++, y--) {
			if (dp[0][i] > dp[0][j]) dp[1][i] = max(dp[1][i], dp[1][j] + 1);
			if (dp[0][x] > dp[0][y]) dp[2][x] = max(dp[2][x], dp[2][y] + 1);
		}
	}
	for (int i = 0; i < n; i++) {
		out = max(out, (dp[1][i] + dp[2][i]));
	}
	cout << out - 1;
	return 0;
}