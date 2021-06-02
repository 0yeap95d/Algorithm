#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

int testcase, K;
string W;
vector<int> pos[27];

void Init() {
	cin >> W >> K;
	for (int i = 0; i < 27; i++) pos[i].clear();
}

void setAlphaPos() {
	int res = 0;
	for (int i = 0; i < W.size(); i++) {
		int idx = W[i] - 'a';
		pos[idx].push_back(i);
	}
}

pair<int, int> getLength() {
	pair<int, int> res(INF, 0);
	for (int i = 0; i < 27; i++) {
		if (pos[i].size() < K) continue;
		int start = 0;
		int end = K - 1;
		while (pos[i].size() != end) {
			int len = pos[i][end++] - pos[i][start++] + 1;
			res.first = min(res.first, len);
			res.second = max(res.second, len);
		}
	}
	return res;
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> testcase;
	while (testcase--) {
		Init();
		setAlphaPos();
		pair<int, int> ans = getLength();
		if (ans.first == INF) cout << -1 << "\n";
		else cout << ans.first << " " << ans.second << "\n";
	}

	return 0;
}