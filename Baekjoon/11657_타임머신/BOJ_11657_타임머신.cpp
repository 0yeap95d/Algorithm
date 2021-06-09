#include <iostream>
#include <vector>
#define MAX 501
#define INF 987654321
using namespace std;

typedef long long ll;

struct Edge {
	int sp;
	int ep;
	ll cost;
};

int N, M;
ll dist[MAX];
vector<Edge> edges;

void init() {

	// N: 도시의 개수, M: 버스 노선의 개수
	cin >> N >> M;

	// dist 초기화
	for (int i = 0; i < MAX; i++) dist[i] = INF;

	// 버스 정보 입력
	int sp, ep;
	ll cost;
	for (int i = 0; i < M; i++) {
		cin >> sp >> ep >> cost;
		edges.push_back({ sp, ep, cost });
	}
}

bool bellmanFord() {
	// 시작위치 설정
	dist[1] = 0;

	// 존재하는 모든 경로를 N-1번 업데이트 하므로써 모든 경우를 탐색
	for (int i = 1; i <= N; i++) {
		for (Edge edge : edges) {
			if (dist[edge.sp] == INF) continue;
			if (dist[edge.ep] > dist[edge.sp] + edge.cost) {
				if (i == N) return true;	// N번째 추가 업데이트를 통해 음수 사이클 판별
				else dist[edge.ep] = dist[edge.sp] + edge.cost;
			}
		}
	}

	return false;
}

void print(bool isCycle) {
	// 음수 사이클이 존재
	if (isCycle) cout << -1;

	// 음수 사이클이 존재하지 않을 때 최단거리 출력
	else {
		for (int i = 2; i <= N; i++) 
			cout << (dist[i] == INF ? -1 : dist[i]) << "\n";
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	init();
	print(bellmanFord());

	return 0;
}