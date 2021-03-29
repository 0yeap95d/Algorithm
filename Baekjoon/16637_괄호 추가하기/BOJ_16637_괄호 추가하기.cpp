#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isAns = false;
int ans = 0;

int compute(int a, int b, char o) {
	if (o == '*') return a * b;
	if (o == '+') return a + b;
	if (o == '-') return a - b;
}

void solve(int idx, vector<int> num, vector<char> oper) {
	if (idx >= oper.size()) {
		for (int i = 0; i < oper.size(); i++) {
			num[i + 1] = compute(num[i], num[i + 1], oper[i]);
			num.erase(num.begin() + i);
			oper.erase(oper.begin() + i);
			i--;
		}
		if (!isAns) {
			ans = num[0];
			isAns = true;
		}
		else ans = max(ans, num[0]);
		return;
	}

	solve(idx + 1, num, oper);
	num[idx + 1] = compute(num[idx], num[idx + 1], oper[idx]);
	num.erase(num.begin() + idx);
	oper.erase(oper.begin() + idx);
	solve(idx + 1, num, oper);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int length, n;
	char c;
	bool isNum = true;

	vector<int> num;
	vector<char> oper;

	cin >> length;
	for (int i = 0; i < length; i++) {
		if (isNum) { cin >> n; num.push_back(n); }
		else { cin >> c; oper.push_back(c); }
		isNum = !isNum;
	}

	solve(0, num, oper);

	cout << ans;

	return 0;
}
