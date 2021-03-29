#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int l, c;
vector<char> inp;
vector<int> check;

void DFS(int select, int depth) {
	// c - depth ������ ���� (�ڱ� ����)
	// l - select ������ ����
	if (c - depth < l - select) return;
	if (select == l) {
		// Ȯ�� �� ���
			// ���� �ϳ� �̻�
			// ���� �ΰ� �̻�
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
	// ����
	check[depth] = 1;
	DFS(select + 1, depth + 1);
	check[depth] = 0;
	// ���� ����
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