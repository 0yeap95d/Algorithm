#include <iostream>
#include <algorithm>
#define SIZE 801
#define INF 987654321
using namespace std;

int N, E, v1, v2, Answer = INF;
int dist[SIZE][SIZE];

void init() {
	cin >> N >> E;

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			if (i == j) continue;
			dist[i][j] = INF;
		}
	}

	int n1, n2, cost;
	for (int i = 0; i < E; i++) {
		cin >> n1 >> n2 >> cost;
		dist[n1][n2] = dist[n2][n1] = cost;
	}
	
	cin >> v1 >> v2;
}

void floydWarshall() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	init();
	floydWarshall();

	if (dist[1][v1] == INF || dist[v1][v2] == INF || dist[v2][N] == INF) Answer = -1;
	else Answer = min(dist[1][v1] + dist[v1][v2] + dist[v2][N], dist[1][v2] + dist[v2][v1] + dist[v1][N]);

	cout << Answer;

	return 0;
}