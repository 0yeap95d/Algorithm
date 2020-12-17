#include <iostream>
#include <vector>
#include <algorithm>
#define SIZE 9
using namespace std;

int N, ans;
int inp[50][9] = { 0, };
vector<bool> visited(SIZE, false);

int playGame(vector<int> order) {
	int ret = 0;
	int num = 0;
	for (int i = 0; i < N; i++) {
		int out = 0;
		int ground[4] = { 0, };
		while (out < 3) {
			int score = inp[i][order[num++]];
			if (num >= SIZE) num = 0;
			if (score == 0) out++;
			else {
				ground[0] = 1;
				for (int p = 3; p >= 0; p--) {
					if (ground[p] == 0) continue;
					else if (p + score > 3) {
						ret++;
						ground[p] = 0;
					}
					else {
						ground[p + score] = 1;
						ground[p] = 0;
					}
				}
			}
		}
	}

	return ret;
}

void setHitter (int idx, vector<int> order){
	if (idx == 3) {
		setHitter(idx + 1, order);
		return;
	}
	if (idx >= SIZE) {
		ans = max(ans, playGame(order));
		return;
	}
	for (int i = 1; i < SIZE; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		order[idx] = i;
		setHitter(idx + 1, order);
		visited[i] = false;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> inp[i][j];
		}
	}
	
	setHitter(0, vector<int>(9, 0));

	cout << ans;

	return 0;
}