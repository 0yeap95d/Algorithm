#include <iostream>
#define SIZE 1000001
#define MOD 1000000009
typedef long long ll;
using namespace std;

int T;
ll DP[SIZE];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// 초기값 셋팅
	DP[1] = 1, DP[2] = 2, DP[3] = 4;
	for (int i = 4; i < SIZE; i++) DP[i] = (DP[i - 1] + DP[i - 2] + DP[i - 3]) % MOD;

	cin >> T;
	int idx;
	while (T--) {
		cin >> idx;
		cout << DP[idx] << "\n";
	}

	return 0;
}