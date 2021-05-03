#include <iostream>
#include <algorithm>
using namespace std;

int N, M, B;
int ground[501][501];
int minHeight = 257;
int maxHeight = -1;

void init() {
	cin >> N >> M >> B;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> ground[i][j];
			minHeight = min(ground[i][j], minHeight);
			maxHeight = max(ground[i][j], maxHeight);
		}
	}
}

void removeBlock() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (ground[i][j] == maxHeight) ground[i][j]--;
		}
	}
}

void addBlock() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (ground[i][j] == minHeight) ground[i][j]++;
		}
	}
}

void solve() {
	int answer = 0;
	while (maxHeight != minHeight) {
		int cntRemoveArea = 0;
		int cntAddArea = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (maxHeight == ground[i][j]) cntRemoveArea++;
				if (minHeight == ground[i][j]) cntAddArea++;
			}
		}

		// 인벤토리에 채울 블록이 충분하지 않거나 채우는 비용이 더 많이 들때
		if (B < cntAddArea || cntRemoveArea * 2 < cntAddArea) {
			removeBlock();
			answer = answer + cntRemoveArea * 2;
			B += cntRemoveArea;
			maxHeight--;
		}
		else {
			addBlock();
			answer = answer + cntAddArea;
			B -= cntAddArea;
			minHeight++;
		}
	}

	cout << answer << " " << maxHeight;
}

int main() {

	init();
	solve();

	return 0;
}