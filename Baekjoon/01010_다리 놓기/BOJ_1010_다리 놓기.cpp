#include <iostream>
#define SIZE 32
using namespace std;

int TC;
int DP[SIZE][SIZE];

void setDP() {
	DP[0][0] = 1;
	for (int i = 1; i < SIZE; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) DP[i][j] = DP[i - 1][j];
			else DP[i][j] = DP[i - 1][j - 1] + DP[i - 1][j];
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	setDP();

	cin >> TC;
	for (int i = 1; i <= TC; i++) {
		int n, m;
		cin >> n >> m;
		cout << DP[m][n] << "\n";
	}

	return 0;
}