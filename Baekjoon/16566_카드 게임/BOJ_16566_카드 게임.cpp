#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K;
vector<int> redCards;
vector<bool> isUsed;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	cin >> N >> M >> K;
	redCards.resize(M); isUsed.resize(M);
	for (int i = 0; i < M; i++) cin >> redCards[i];
	sort(redCards.begin(), redCards.end());

	while (K--) {
		int num;
		cin >> num;

		int idx = upper_bound(redCards.begin(), redCards.end(), num) - redCards.begin();
		while (isUsed[idx]) idx++;
		isUsed[idx] = true;
		cout << redCards[idx] << '\n';
	}

	return 0;
}