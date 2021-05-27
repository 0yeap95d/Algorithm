#include <iostream>
#include <vector>
#define MAX 102
#define INF 987654321
using namespace std;

int N, M;
int dist[MAX][MAX];
int trace[MAX][MAX];

void Init() {
	cin >> N;
	cin >> M;

	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			dist[i][j] = i == j ? 0 : INF;
		}
	}

	int v1, v2, d;
	for (int i = 0; i < M; i++) {
		cin >> v1 >> v2 >> d;
		if (dist[v1][v2] > d) dist[v1][v2] = d;
	}
}

void Floyd() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					trace[i][j] = k;
				}
			}
		}
	}
}

vector<int> PathTrace(int i, int j) {
	vector<int> left, right, res;

	int k = trace[i][j];
	if (k == 0) return res;
	
	left = PathTrace(i, k);
	for (int path : left) res.push_back(path);
	res.push_back(k);
	right = PathTrace(k, j);
	for (int path : right) res.push_back(path);

	return res;
}

void Print() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (dist[i][j] == INF) dist[i][j] = 0;
			cout << dist[i][j] << " ";
		}
		cout << "\n";
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (dist[i][j] == 0) {
				cout << 0 << '\n';
				continue;
			}

			vector<int> path;
			path.push_back(i);
			for (int p : PathTrace(i, j)) path.push_back(p);
			path.push_back(j);
			
			cout << path.size() << " ";
			for (int p : path) cout << p << " ";
			cout << '\n';
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	Init();
	Floyd();
	Print();

	return 0;
}