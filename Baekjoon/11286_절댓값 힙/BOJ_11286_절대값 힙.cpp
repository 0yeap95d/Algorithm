#include <iostream>
#include <queue>
#include <cstdlib>
using namespace std;

struct cmp {
	bool operator()(int p1, int p2) {
		if (abs(p1) == abs(p2)) return p1 > p2;
		else return abs(p1) > abs(p2);
	}
};

int N;
priority_queue<int, vector<int>, cmp> pq;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N;
	while (N--) {
		int x;
		cin >> x;

		if (x == 0) {
			if (pq.empty()) cout << 0 << "\n";
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else pq.push(x);
	}

	return 0;
}