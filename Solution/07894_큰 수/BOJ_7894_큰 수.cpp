#include <iostream>
#include <cmath>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// �׽�Ʈ ���̽��� �� N �Է�
	int N;
	cin >> N;

	double m, ans;
	while (N--) {
		cin >> m;
		ans = 0;
		for (double i = m; i > 0; i--) {
			ans += log10(i);
		}

		cout << (int)(ans + 1) << "\n" ;
	}

	

	return 0;
}