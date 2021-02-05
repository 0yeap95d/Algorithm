#include <iostream>
#include <cstring>
#include <algorithm>
#define SIZE 760
using namespace std;

int R, C, Ans;
bool Mine[SIZE][SIZE]; 
int Right[SIZE][SIZE], Left[SIZE][SIZE];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> R >> C;
	string inp;
	for (int i = 1; i <= R; i++) {
		cin >> inp;
		for (int j = 1; j <= C; j++) Mine[i][j] = inp[j - 1] - '0';
	}

	for (int i = R; i > 0; i--) {
		for (int j = 1; j <= C; j++) {
			if (!Mine[i][j]) continue;
			Left[i][j] = Left[i + 1][j - 1] + 1;
			Right[i][j] = Right[i + 1][j + 1] + 1;
		}
	}

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			for (int k = Left[i][j] - 1; k >= Ans; k--) {
				if (Right[i][j] >= k + 1 && Right[i + k][j - k] >= k + 1 && Left[i + k][j + k] >= k + 1) Ans = k + 1;
			}
		}
	}

	cout << Ans;

	return 0;
}