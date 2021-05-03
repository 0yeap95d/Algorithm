#include <iostream>
#include <set>
using namespace std;

int testcase, k;
multiset<int> pq;

void init() {
	cin >> k;
	pq.clear();
}

void inputCommand() {
	char command;
	int num;

	cin >> command >> num;

	if (command == 'I') pq.insert(num);

	else if (command == 'D') {
		if (pq.empty()) return;
		if (num > 0) pq.erase(--pq.end());
		else pq.erase(pq.begin());
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> testcase;

	while (testcase--) {
		init();
		while (k--) inputCommand();
		
		if (pq.empty()) cout << "EMPTY\n";
		else cout << *(--pq.end()) << " " << *pq.begin() << "\n";
	}

	return 0;
}