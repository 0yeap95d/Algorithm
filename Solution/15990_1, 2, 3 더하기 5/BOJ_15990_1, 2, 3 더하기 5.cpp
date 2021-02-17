#include <iostream>
#define SIZE 100001
#define MOD 1000000009
using namespace std;

int N, Ans;
int dp[100001][3];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	dp[1][0] = dp[2][1] = dp[3][0] = dp[3][1] = dp[3][2] = 1;
	for (int i = 4; i < SIZE; i++) {
		dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % MOD;
		dp[i][1] = (dp[i - 2][0] + dp[i - 2][2]) % MOD;
		dp[i][2] = (dp[i - 3][0] + dp[i - 3][1]) % MOD;
	}

	cin >> N;
	int inp;
	for (int i = 0; i < N; i++) {
		cin >> inp;
		Ans = 0;
		for (int j = 0; j < 3; j++) Ans = (Ans + dp[inp][j]) % MOD;
		cout << Ans << "\n";
	}

	return 0;
}