#include <iostream>
#include <queue>
#include <algorithm>
#define SIZE 1001
#define INF 987654321
using namespace std;

struct City {
	int start;
	int end;
	int cost;
};

bool operator<(City city1, City city2) {
	return city1.cost > city2.cost;
}

int N, M;
int graph[SIZE][SIZE];
bool visited[SIZE];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			graph[i][j] = INF;
		}
	}

	int start, end, cost;
	for (int i = 0; i < M; i++) {
		cin >> start >> end >> cost;
		graph[start][end] = min(graph[start][end], cost);
	}

	cin >> start >> end;

	priority_queue<City> pq;
	pq.push({ start, start, 0 });
	visited[start] = true;

	int ans = INF;
	while (!pq.empty() && pq.top().end != end) {
		City city = pq.top();
		visited[city.end] = true;
		pq.pop();
		if (city.cost > graph[start][city.end]) continue;
		for (int i = 1; i <= N; i++) {
			if (graph[city.end][i] == INF || visited[i]) continue;
			pq.push({ start, i, city.cost + graph[city.end][i] });
		}
	}

	cout << pq.top().cost;

	return 0;
}