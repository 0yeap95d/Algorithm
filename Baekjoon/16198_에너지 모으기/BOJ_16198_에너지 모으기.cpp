#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, Answer;

void getEnergy(vector<int> marbles, int sum) {
	if (marbles.size() == 2) {
		Answer = max(Answer, sum);
		return;
	}

	vector<int> temp;
	for (int i = 1; i < marbles.size() - 1; i++) {
		temp.assign(marbles.begin(), marbles.end());
		temp.erase(temp.begin() + i);
		getEnergy(temp, sum + marbles[i - 1] * marbles[i + 1]);
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N;
	vector<int> marbles(N);
	for (int i = 0; i < N; i++) cin >> marbles[i];
	getEnergy(marbles, 0);
	
	cout << Answer;

	return 0;
}