#include <iostream>
#include <string.h>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	string a, b;
	cin >> a >> b;

	int x, y;
	x = y = -1;

	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b.size(); j++) {
			if (a[i] != b[j]) continue;
			x = i;
			y = j;
			break;
		}
		if (x >= 0) break;
	}

	char ans[31][31];
	memset(ans, '.', sizeof(ans));
	for (int i = 0; i < a.size(); i++) ans[y][i] = a[i];
	for (int i = 0; i < b.size(); i++) ans[i][x] = b[i];

	for (int i = 0; i < b.size(); i++) {
		for (int j = 0; j < a.size(); j++) {
			cout << ans[i][j];
		}
		cout << "\n";
	}

	return 0;
}