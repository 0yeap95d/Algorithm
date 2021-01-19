#include <iostream>
#include <cstring>
#include <algorithm>
#define SIZE 101
using namespace std;

int N, M;
string dp[SIZE][SIZE];

string Add_Num(string num1, string num2) {
	long long sum = 0;
	string result;

	while (!num1.empty() || !num2.empty()) {
		if (!num1.empty()) {
			sum += num1.back() - '0';
			num1.pop_back();
		}
		if (!num2.empty()) {
			sum += num2.back() - '0';
			num2.pop_back();
		}
		result.push_back((sum % 10) + '0');
		sum /= 10;
	}

	while (sum != 0) {
		result.push_back((sum % 10) + '0');
		sum /= 10;
	}

	reverse(result.begin(), result.end());
	return result;
}

int main() {

	cin >> N >> M;
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= i; j++) {
			if (i == j || j == 0) dp[i][j] = '1';
			else dp[i][j] = Add_Num(dp[i - 1][j - 1], dp[i - 1][j]);
		}
	}

	cout << dp[N][M];

	return 0;
}