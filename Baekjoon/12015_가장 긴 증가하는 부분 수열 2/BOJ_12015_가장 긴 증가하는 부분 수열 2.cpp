#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N, num;
	vector<int> arr(1, 0);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		if (num > arr.back()) arr.push_back(num);
		else *lower_bound(arr.begin(), arr.end(), num) = num;
	}
	cout << arr.size() - 1;

	return 0;
}