#include <iostream>
#include <queue>
#include <map>
typedef long long ll;
using namespace std;

int A, B;
map<ll, bool> visited;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> A >> B;

	queue<pair<ll, int>> que;
	que.push({ A, 1 });
	visited[A] = true;

	while (!que.empty()) {
		ll a = que.front().first;
		int cnt = que.front().second;
		que.pop();

		if (a * 2 <= B && !visited[a * 2]) {
			if (a * 2 == B) {
				cout << cnt + 1;
				return 0;
			}
			que.push({ a * 2, cnt + 1 });
			visited[a * 2] = true;
		}
		
		if (a * 10 + 1 <= B && !visited[a * 10 + 1]) {
			if (a * 10 + 1 == B) {
				cout << cnt + 1;
				return 0;
			}
			que.push({ a * 10 + 1, cnt + 1 });
		}
	}
	cout << -1;

	return 0;
}