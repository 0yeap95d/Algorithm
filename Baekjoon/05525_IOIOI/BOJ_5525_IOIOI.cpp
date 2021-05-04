#include <iostream>
#include <cstring>
using namespace std;

int N, M, Answer;
string S;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> M >> S;

	int cnt = 0;
	bool orderI = true;
	for (int i = 0; i < M; i++) {

		if (S[i] == 'I') {
			if (orderI) {
				cnt++;
				orderI = !orderI;
				if (cnt >= N * 2 + 1) Answer++;
			}
			else cnt = 1;
		}
		else if (S[i] == 'O') {
			if (!orderI) {
				cnt++;
				orderI = !orderI;
			}
			else cnt = 0;
		}
	}

	cout << Answer;

	return 0;
}