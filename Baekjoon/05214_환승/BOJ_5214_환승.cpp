#include <iostream>
#include <vector>
#include <queue>
#define ST_SIZE 1001
#define TUBE_SIZE 100001
using namespace std;

int N, K, M, Ans = -1;
int Connect[ST_SIZE][ST_SIZE];
vector<int> Tube[TUBE_SIZE];
queue<pair<int, int>> que;
bool visited[TUBE_SIZE];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> K >> M;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < K; j++) {
			cin >> Connect[i][j];
			Tube[Connect[i][j]].push_back(i);
		}
	}

	que.push({ 1, 1 });
	visited[1] = true;
	while (!que.empty()) {
		int v = que.front().first;
		int t = que.front().second;
		que.pop();

		if (v == N) {
			Ans = t;
			break;
		}

		for (int tube : Tube[v]) {
			for (int k = 0; k < K; k++) {
				int nv = Connect[tube][k];
				if (visited[nv]) continue;
				que.push({ nv, t + 1 });
				visited[nv] = true;
			}
		}
	}

	cout << Ans;

	return 0;
}