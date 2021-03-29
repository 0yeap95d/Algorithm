#include <iostream>
#define SIZE 2502
#define MOD 1000000007
using namespace std;

int testcase, inp;
long long dp[SIZE][SIZE / 2];
long long Ans[SIZE];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	Ans[1] = dp[1][0] = 1;
	for (int i = 2; i < SIZE; i++) {
		for (int j = 0; j <= i / 2; j++) {
			if (j == 0) dp[i][j] = 1;
			else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
			Ans[i] = (Ans[i] + (dp[i][j] * dp[i][j])) % MOD;
		}
	}

	cin >> testcase;
	while (testcase--) {
		cin >> inp;
		if (inp % 2 != 0) cout << 0;
		else cout << Ans[inp / 2];
		cout << "\n";
	}


	return 0;
}