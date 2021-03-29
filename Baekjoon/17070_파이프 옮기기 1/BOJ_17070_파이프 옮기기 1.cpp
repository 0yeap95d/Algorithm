#include <iostream>
#include <vector>
#define SIZE 18
using namespace std;

int check[SIZE][SIZE][4];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, inp, ans = 0;
	cin >> N;
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) cin >> check[i][j][0];
	}

	check[1][1][1] = 1;
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			if (check[i][j][0] == 1) continue;
			if (i == N && j == N) ans = check[i][j - 1][1] + check[i - 1][j - 1][2] + check[i - 1][j][3];
			check[i][j][1] += check[i][j - 1][1] + check[i - 1][j - 1][2];
			check[i][j][3] += check[i - 1][j - 1][2] + check[i - 1][j][3];
			if (check[i + 1][j][0] != 1 && check[i][j + 1][0] != 1) check[i][j][2] += check[i][j - 1][1] + check[i - 1][j - 1][2] + check[i - 1][j][3];
		}
	}

	cout << ans;

	return 0;
}