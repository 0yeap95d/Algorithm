#include <iostream>
#include <map>
using namespace std;

bool visited[2000000];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N, C, inp, ans = 0;
	cin >> N >> C;

	for (int i = 0; i < N; i++) {
		cin >> inp;
		for (int j = 1; j * inp <= C; j++) {
			if (visited[j * inp]) continue;
			visited[j * inp] = true;
			ans++;
		}
	}

	cout << ans;

	return 0;
}