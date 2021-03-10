#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int N;
vector<int> arr, temp;
map<int, int> comp;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N;
	arr.resize(N);
	for (int i = 0; i < N; i++) cin >> arr[i];
	temp.assign(arr.begin(), arr.end());
	sort(temp.begin(), temp.end());

	int cnt = 1;
	for (int i = 0; i < N; i++) {
		int num = temp[i];
		if (comp[num] != 0) continue;
		comp[num] = cnt++;
	}

	for (int i = 0; i < N; i++) cout << comp[arr[i]] - 1 << " ";
	

	return 0;
}