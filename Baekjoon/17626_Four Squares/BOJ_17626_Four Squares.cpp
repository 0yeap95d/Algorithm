#include <iostream>
#include <cmath>
#include <algorithm>
#define MAX 50001
using namespace std;

int n;
int dp[50001];

void setDpTable() {
	for (int i = 0; i < MAX; i++) {
		if (i <= sqrt(MAX)) dp[i * i] = 1;
		if (dp[i] == 0) dp[i] = MAX;
	}

	dp[0] = dp[1] = 1;
	for (int i = 2; i < MAX; i++) {
		for (int j = 1; j * j <= i; j++) {
			dp[i] = min(dp[i], dp[j * j] + dp[i - j * j]);
		}
	}
}

int main() {
	
	setDpTable();

	cin >> n;
	cout << dp[n];

	return 0;
}