#include <iostream>
#include <queue>
#define endl '\n'
using namespace std;

int N;
priority_queue<int> pq;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N;
	
	int command;
	for (int i = 0; i < N; i++) {
		cin >> command;
		if (command == 0) {
			if (pq.empty()) cout << 0 << endl;
			else {
				cout << pq.top() << endl;
				pq.pop();
			}
		}
		else pq.push(command);
	}

	return 0;
}