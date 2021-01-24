#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[105][100005];

bool cmp(const pair<int, int>& p1, const pair<int, int>& p2) {
	if (p1.first == p2.first) return p1.second < p2.second;
	return p1.first < p2.first;
}

int main() {
	int n, k, w, v, Answer = 0;
	cin >> n >> k;

	vector<pair<int, int>> inp;

	for (int i = 0; i < n; i++) {
		cin >> w >> v;
		inp.push_back(make_pair(w, v));
	}
	sort(inp.begin(), inp.end(), cmp);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= k; j++) {
			if (j < inp[i].first) dp[i + 1][j] = dp[i][j];
			else dp[i + 1][j] = max(dp[i][j], dp[i][j - inp[i].first] + inp[i].second);
		}
	}

	cout << dp[n][k] << endl;

	return 0;
}
