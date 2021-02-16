#include <iostream>
#include <algorithm>
#define SIZE 1001
using namespace std;

int N;
int P[SIZE];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> P[i];
		for (int j = 1; j <= i / 2; j++) P[i] = min(P[i], P[j] + P[i - j]);
	}

	cout << P[N];

	return 0;
}