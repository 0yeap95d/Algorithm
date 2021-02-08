#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

ll N, Ans;
int Dice[6];
vector<int> Val;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < 6; i++) cin >> Dice[i];

	if (N == 1) { 
		int maxVal = 0;
		for (int i = 0; i < 6; i++) {
			Ans += Dice[i];
			maxVal = max(maxVal, Dice[i]);
		}
		Ans -= maxVal;
	}
	else {
		Val.push_back(min(Dice[0], Dice[5]));
		Val.push_back(min(Dice[1], Dice[4]));
		Val.push_back(min(Dice[2], Dice[3]));

		sort(Val.begin(), Val.end());

		Ans += ((5 * N * N) - (8 * N) + 4) * Val[0];
		Ans += 8 * (N - 1) * Val[1];
		Ans += 4 * Val[2];
	}

	cout << Ans;

	return 0;
}