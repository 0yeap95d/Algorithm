#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> inp(N, 0);
	for (int i = 0; i < N; i++) cin >> inp[i];

	if (next_permutation(inp.begin(), inp.end())) {
		for (int i = 0; i < N; i++) cout << inp[i] << " ";
	}
	else cout << -1;

	return 0;
}