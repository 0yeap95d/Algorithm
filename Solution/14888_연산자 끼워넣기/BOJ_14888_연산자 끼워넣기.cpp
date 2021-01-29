#include <iostream>
#include <algorithm>
#define SIZE 11
#define INF 2100000000
using namespace std;

int N;
int numArr[SIZE];
int cntOper[4];

int MAX_VAL = -INF;
int MIN_VAL = INF;

void DFS(int depth, int res) {
	if (depth == N) {
		MAX_VAL = max(MAX_VAL, res);
		MIN_VAL = min(MIN_VAL, res);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (cntOper[i] == 0) continue;

		cntOper[i]--;
		if (i == 0) DFS(depth + 1, res + numArr[depth]);
		else if (i == 1) DFS(depth + 1, res - numArr[depth]);
		else if (i == 2) DFS(depth + 1, res * numArr[depth]);
		else if (i == 3) DFS(depth + 1, res / numArr[depth]);
		cntOper[i]++;
	}
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> numArr[i];
	for (int i = 0; i < 4; i++) cin >> cntOper[i];

	DFS(1, numArr[0]);

	cout << MAX_VAL << "\n";
	cout << MIN_VAL << "\n";

	return 0;
}