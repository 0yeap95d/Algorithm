#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> arr;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N;

	int inp;
	for (int i = 0; i < N; i++) {
		cin >> inp;
		arr.push_back(inp);
	}

	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	for (int a : arr) cout << a << ' ';

	return 0;
}