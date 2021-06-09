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

	// N: ������ ����, M: ���� �뼱�� ����
	cin >> N >> M;

	// dist �ʱ�ȭ
	for (int i = 0; i < MAX; i++) dist[i] = INF;

	// ���� ���� �Է�
	int sp, ep;
	ll cost;
	for (int i = 0; i < M; i++) {
		cin >> sp >> ep >> cost;
		edges.push_back({ sp, ep, cost });
	}
}

bool bellmanFord() {
	// ������ġ ����
	dist[1] = 0;

	// �����ϴ� ��� ��θ� N-1�� ������Ʈ �ϹǷν� ��� ��츦 Ž��
	for (int i = 1; i <= N; i++) {
		for (Edge edge : edges) {
			if (dist[edge.sp] == INF) continue;
			if (dist[edge.ep] > dist[edge.sp] + edge.cost) {
				if (i == N) return true;	// N��° �߰� ������Ʈ�� ���� ���� ����Ŭ �Ǻ�
				else dist[edge.ep] = dist[edge.sp] + edge.cost;
			}
		}
	}

	return false;
}

void print(bool isCycle) {
	// ���� ����Ŭ�� ����
	if (isCycle) cout << -1;

	// ���� ����Ŭ�� �������� ���� �� �ִܰŸ� ���
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