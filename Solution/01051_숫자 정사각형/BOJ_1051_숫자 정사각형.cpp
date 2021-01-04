#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	string inp;
	vector<vector<int>> rec(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++) {
		cin >> inp;
		for (int j = 0; j < M; j++) rec[i][j] = inp[j] - '0';
	}

	int ans = 0;
	int maxRange = max(N, M);
	int minRange = min(N, M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int d = 0; d < maxRange; d++) {
				if (i + d >= N || j + d >= M) break;
				if (rec[i][j] == rec[i + d][j] &&
					rec[i][j] == rec[i][j + d] &&
					rec[i][j] == rec[i + d][j + d]) ans = max(ans, (d + 1) * (d + 1));
			}
		}
	}

	cout << ans;

	return 0;
}