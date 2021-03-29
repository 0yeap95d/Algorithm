#include <iostream>
#include <algorithm>
#define SIZE 100001
using namespace std;

int N, Ans;
int Arr[SIZE], Dp[SIZE][2];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> Arr[i];
	
	Ans = Dp[0][0] = Arr[0];
	for (int i = 1; i < N; i++) {
		Dp[i][0] = max(Dp[i - 1][0] + Arr[i], Arr[i]);
		Dp[i][1] = max(Dp[i - 1][0], Dp[i - 1][1] + Arr[i]);
		Ans = max(Ans, max(Dp[i][0], Dp[i][1]));
	}

	cout << Ans;

	return 0;
}