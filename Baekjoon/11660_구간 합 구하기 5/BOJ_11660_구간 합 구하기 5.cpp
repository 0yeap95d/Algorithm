#include <iostream>
#define SIZE 1030
#define lli long long int
using namespace std;

int N, M;
lli dp[SIZE][SIZE];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> M;

	// 입력, 누적 합
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> dp[i][j];
			dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
		}
	}
	
	int sx, sy, ex, ey;
	for (int i = 0; i < M; i++) {
		cin >> sx >> sy >> ex >> ey;
		sx--; sy--;
		cout << dp[ex][ey] - dp[ex][sy] - dp[sx][ey] + dp[sx][sy] << "\n";
	}

	return 0;
}