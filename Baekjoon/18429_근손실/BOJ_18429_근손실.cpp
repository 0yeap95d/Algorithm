#include <iostream>
#include <algorithm>
using namespace std;

int N, K, ans;
int weight[8];
bool visited[8];

void backTracking(int sum, int level) {

	if (level >= N) {
		ans++;
		return;
	}

	for (int i = 0; i < N; i++) {
		if (visited[i]) continue;
		if (sum + weight[i] - K < 0) continue;
		visited[i] = true;
		backTracking(sum + weight[i] - K, level + 1);
		visited[i] = false;
	}
}

int main() {

	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> weight[i];
	backTracking(0, 0);
	cout << ans;

	return 0;
}