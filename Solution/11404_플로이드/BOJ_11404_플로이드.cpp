#include <iostream>
#include <algorithm>
#define MAX_SIZE 101
#define INF 987654321
using namespace std;

int n, m;
int city[MAX_SIZE][MAX_SIZE];

void FloydWarshall() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				city[i][j] = min(city[i][j], city[i][k] + city[k][j]);
			}
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	// 도시의 개수 n, 버스의 개수 m 입력
	cin >> n >> m;

	// 버스 정보 초기화
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) city[i][j] = 0;
			else city[i][j] = INF;
		}
	}

	// 버스 정보 입력
	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		city[a][b] = min(city[a][b], c);
	}

	// 플로이드-와샬 알고리즘
	FloydWarshall();

	// 정답 출력
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (city[i][j] == INF) city[i][j] = 0;
			cout << city[i][j] << " ";
		}
		cout << "\n";
	}
	

	return 0;
}