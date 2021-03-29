#include <stdio.h>
#include <vector>
#pragma warning(disable:4996)
using namespace std;

vector<int> ans;


int main() {
	int inp, cnt = 0, max = 0;
	long long out = 0;
	bool check = true;
	scanf("%d", &inp);

	ans.resize(11, 0);

	while (cnt != inp) {
		ans[0]++;
		for (int i = 0; i <= max; i++) {
			if (i + 1 <= max && ans[i + 1] <= ans[i]) {
				ans[i] = 0;
				ans[i + 1]++;
			}
			if (ans[i] == 10) {
				if (i == max) max++;
				ans[i] = 0;
				ans[i + 1]++;
			}
			if (max == 10) break;
		}
		if (max == 10) break;
		check = true;
		for (int i = 0; i <= max; i++) {
			if (i + 1 <= max && ans[i + 1] <= ans[i]) {
				check = false;
				break;
			}
		}
		if (check) cnt++;
	}

	if (max == 10) out = -1;
	else {
		while (!ans.empty()) {
			out *= 10;
			out += ans.back();
			ans.pop_back();
		}
	}

	printf("%lld", out);

	return 0;
}