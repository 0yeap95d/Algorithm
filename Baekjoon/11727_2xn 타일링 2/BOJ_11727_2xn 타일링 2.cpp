#include <iostream>
using namespace std;

int sum(int a, int b);

int main() {
	int dp[1001];
	dp[0] = 1;
	dp[1] = 1;

	int input;
	cin >> input;
	for (int i = 2; i <= input; i++) {
		dp[i] = sum(dp[i - 1], dp[i - 2] * 2);
	}

	cout << dp[input];

	return 0;
}

int sum(int a, int b) {
	int result = a + b;
	if (result > 10006) result %= 10007;
	return result;
}