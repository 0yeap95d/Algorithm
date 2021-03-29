#include <iostream>
#include <algorithm>
using namespace std;

int T, W, Ans;
int DP[1002][32][2];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> T >> W;

	int inp;
	for (int t = 1; t <= T; t++) {
		cin >> inp;
		for (int w = 1; w <= W + 1; w++) {
			DP[t][w][0] = max(DP[t - 1][w][0], DP[t - 1][w - 1][1]);
			DP[t][w][1] = max(DP[t - 1][w][1], DP[t - 1][w - 1][0]);
			if (inp == 1) DP[t][w][0]++;
			else if (t == 1 && w == 1) continue;
			else DP[t][w][1]++;
		}
	}

	for (int w = 1; w <= W + 1; w++) Ans = max(Ans, max(DP[T][w][0], DP[T][w][1]));

	cout << Ans;

	return 0;
}