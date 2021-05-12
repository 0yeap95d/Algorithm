#include <iostream>
#include <vector>
#define SIZE 501
#define INF 987654321
using namespace std;

struct Edge {
	int sp;
	int ep;
	int cost;
};

int N, M, W;
int dist[SIZE];
vector<Edge> edges;

void init() {
	// N: 도시의 개수, M: 도로의 개수, W: 웜홀의 개수
	cin >> N >> M >> W;

	// dist 초기화
	for (int i = 0; i < SIZE; i++) dist[i] = -1;
	
	// edges 초기화
	edges.clear();

	// 도로 정보 입력
	int S, E, T;
	for (int i = 0; i < M; i++) {
		cin >> S >> E >> T;
		edges.push_back({ S, E, T });
		edges.push_back({ E, S, T });
	}

	// 웜홀 정보 입력
	for (int i = 0; i < W; i++) {
		cin >> S >> E >> T;
		edges.push_back({ S, E, -T });
	}
}

bool bellmanFord() {
	
	dist[1] = 0;

	// 존재하는 모든 경로를 N-1번 업데이트 하므로써 모든 경우를 탐색
	for (int i = 1; i < N; i++) {
		for (Edge edge : edges) {
			if (dist[edge.ep] > dist[edge.sp] + edge.cost) 
				dist[edge.ep] = dist[edge.sp] + edge.cost;
		}
	}

	// 완성된 그래프에서 한번 더 돌렸을때 값이 변경된다면 음수사이클이 존재한다고 판단
	for (Edge edge : edges) 
		if (dist[edge.ep] > dist[edge.sp] + edge.cost) return true;
	
	return false;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int tc;
	cin >> tc;

	while (tc--) {
		init();
		if (bellmanFord()) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}