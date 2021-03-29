#include<iostream>
#include<vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> ans;
	for (int i = 1; i <= N; i++) {
		vector<int> temp;
		temp.push_back(N);
		int gap = i;
		int idx = 0;
		while (gap >= 0) {
			temp.push_back(gap);
			gap = temp[idx++] - gap;
		}
		if (ans.size() < temp.size()) ans.assign(temp.begin(), temp.end());
	}

	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";

	return 0;
}