#include <iostream>
#define SIZE 10001
using namespace std;

int testcase;
int dp[SIZE][3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	for (int i = 1; i <= 3; i++) {
		for (int j = 0; j < i; j++) 
			dp[i][j] = 1;
	}

	for (int i = 4; i < SIZE; i++) {
		dp[i][0] = dp[i - 1][0];
		dp[i][1] = dp[i - 2][0] + dp[i - 2][1];
		dp[i][2] = dp[i - 3][0] + dp[i - 3][1] + dp[i - 3][2];
	}

	cin >> testcase;

	int idx;
	while (testcase--) {
		cin >> idx;
		cout << dp[idx][0] + dp[idx][1] + dp[idx][2] << "\n";
	}

	return 0;
}