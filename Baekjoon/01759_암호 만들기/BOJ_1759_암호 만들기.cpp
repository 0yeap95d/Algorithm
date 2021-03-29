#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int l, c;
vector<char> inp;
vector<int> check;

void DFS(int select, int depth) {
	// c - depth 남은거 갯수 (자기 포함)
	// l - select 골라야할 갯수
	if (c - depth < l - select) return;
	if (select == l) {
		// 확인 후 출력
			// 모음 하나 이상
			// 자음 두개 이상
		int cnt1, cnt2;
		cnt1 = cnt2 = 0;

		vector<char> res;
		for (int i = 0; i < c; i++) {
			if (check[i] == 0) continue;
			if (inp[i] == 'a' ||
				inp[i] == 'e' ||
				inp[i] == 'i' ||
				inp[i] == 'o' ||
				inp[i] == 'u') cnt1++;
			else cnt2++;
			res.push_back(inp[i]);
		}

		if (cnt1 >= 1 && cnt2 >= 2) {
			for (char c : res) cout << c;
			cout << endl;
		}

		return;
	}
	// 선택
	check[depth] = 1;
	DFS(select + 1, depth + 1);
	check[depth] = 0;
	// 선택 안함
	DFS(select, depth + 1);
}

int main() {

	cin >> l >> c;

	inp.assign(c, ' ');
	check.assign(c, 0);

	for (int i = 0; i < c; i++) cin >> inp[i];
	sort(inp.begin(), inp.end());

	DFS(0, 0);

	return 0;
}