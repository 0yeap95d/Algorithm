#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

ll N, M, Answer;
vector<ll> costs;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	ll low, high;
	low = high = 0;

	cin >> N >> M;
	costs.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> costs[i];
		high = max(high, costs[i]);
	}
	high = high * M;

	while (low <= high) {
		ll sum = 0;
		ll mid = (low + high) / 2;

		for (ll cost : costs) sum += mid / cost;
		if (sum >= M) high = mid - 1;
		else low = mid + 1;
	}
	Answer = high + 1;

	cout << Answer;

	return 0;
}