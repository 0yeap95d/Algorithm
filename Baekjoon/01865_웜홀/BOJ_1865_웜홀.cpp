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
	// N: ������ ����, M: ������ ����, W: ��Ȧ�� ����
	cin >> N >> M >> W;

	// dist �ʱ�ȭ
	for (int i = 0; i < SIZE; i++) dist[i] = -1;
	
	// edges �ʱ�ȭ
	edges.clear();

	// ���� ���� �Է�
	int S, E, T;
	for (int i = 0; i < M; i++) {
		cin >> S >> E >> T;
		edges.push_back({ S, E, T });
		edges.push_back({ E, S, T });
	}

	// ��Ȧ ���� �Է�
	for (int i = 0; i < W; i++) {
		cin >> S >> E >> T;
		edges.push_back({ S, E, -T });
	}
}

bool bellmanFord() {
	
	dist[1] = 0;

	// �����ϴ� ��� ��θ� N-1�� ������Ʈ �ϹǷν� ��� ��츦 Ž��
	for (int i = 1; i < N; i++) {
		for (Edge edge : edges) {
			if (dist[edge.ep] > dist[edge.sp] + edge.cost) 
				dist[edge.ep] = dist[edge.sp] + edge.cost;
		}
	}

	// �ϼ��� �׷������� �ѹ� �� �������� ���� ����ȴٸ� ��������Ŭ�� �����Ѵٰ� �Ǵ�
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