#include <iostream>
#define SIZE 101
#define INF 987654321
using namespace std;

int n, m, r, Answer;
int items[SIZE];
int graph[SIZE][SIZE];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// ������ ���� n, �������� m, ���� ���� r
	cin >> n >> m >> r;

	// �� ���� ������ �� items
	for (int i = 1; i <= n; i++) cin >> items[i];

	// ������ȣ a, b�� ���� ���� l
	int a, b, l;
	for (int i = 0; i < r; i++) {
		cin >> a >> b >> l;
		graph[a][b] = graph[b][a] = l;
	}

	// �÷��̵� �ͼ� �˰����� ������ ���� �׷��� ����
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j || graph[i][j] != 0) continue;
			graph[i][j] = INF;
		}
	}

	// �÷��̵� �ͼ� �˰���
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (graph[i][j] > graph[i][k] + graph[k][j])
					graph[i][j] = graph[i][k] + graph[k][j];
			}
		}
	}

	// �� ������ ���� �� �ִ� �ִ� ������
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			if (graph[i][j] <= m) sum += items[j];
		}
		if (Answer < sum) Answer = sum;
	}

	// ���
	cout << Answer;

	return 0;
}


/*
input
5 5 4
5 7 8 2 3
1 4 5
5 2 4
3 2 3
1 2 3
*/