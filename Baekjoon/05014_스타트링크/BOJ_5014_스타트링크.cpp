#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int F, S, G, U, D, ans = -1;
	cin >> F >> S >> G >> U >> D;

	vector<bool> visited(1000001, false);
	queue<pair<int, int>> que;
	que.push(make_pair(0, S));
	visited[S] = true;

	if (S == G) ans = 0;

	while (!que.empty()) {
		int num = que.front().first;
		int floor = que.front().second;
		que.pop();

		int nextUp = floor + U;
		int nextDown = floor - D;

		if (nextUp == G || nextDown == G) {
			ans = num + 1;
			break;
		}

		if (nextUp <= F && !visited[nextUp]) {
			que.push(make_pair(num + 1, nextUp));
			visited[nextUp] = true;
		}

		if (nextDown > 0 && !visited[nextDown]) {
			que.push(make_pair(num + 1, nextDown));
			visited[nextDown] = true;
		}
		
	}

	if (ans < 0) cout << "use the stairs\n";
	else cout << ans;

	return 0;
}