#include <iostream>
#include <cstring>
using namespace std;

int N;

bool isOverlap(string str, int idx) {
	int size = (idx + 1) / 2;
	for (int i = 1; i <= size; i++) {
		int sp1 = idx, sp2 = idx - i;
		bool isSame = true;
		for (int j = 0; j < i; j++) {
			if (str.at(sp1) != str.at(sp2)) {
				isSame = false;
				break;
			}
			sp1--; sp2--;
		}
		if (isSame) return true;
	}
	return false;
}

bool backTracking(string str, int idx) {

	if (isOverlap(str, idx - 1)) return false;

	if (idx == N) {
		cout << str << endl;
		return true;
	}

	for (int i = 1; i <= 3; i++) {
		char ch = i + '0';
		if (backTracking(str + ch, idx + 1)) return true;
	}

	return false;
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N;
	backTracking("", 0);

	return 0;
}