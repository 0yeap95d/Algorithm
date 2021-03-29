#include <iostream>
#include <map>
typedef long long ll;
using namespace std;

ll G;
map<ll, int> Pow_Num;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> G;

	ll limit = (G + 1) / 2;
	bool isAns = false;
	for (ll i = 1; i <= limit; i++) {
		ll key = i * i;
		Pow_Num[key] = i;
		if (key > G&& Pow_Num[key - G] != 0) {
			cout << i << "\n";
			isAns = true;
		}
	}

	if (!isAns) cout << -1;

	return 0;
}