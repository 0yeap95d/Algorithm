#include <iostream>
#include <vector>
#define SIZE 2001
using namespace std;

int N, M;
vector<int> AdjList[SIZE];
bool Visited[SIZE];

bool DFS(int depth, int idx) {

	// 깊이가 4이면 조건 성립
	if (depth >= 4) return true;

	bool isAns = false;
	for (int v : AdjList[idx]) {
		if (Visited[v]) continue;
		Visited[v] = true;
		isAns = DFS(depth + 1, v);
		Visited[v] = false;
		if (isAns) return true;
	}

	return false;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// 데이터 입력
	cin >> N >> M;
	int v1, v2;
	for (int i = 0; i < M; i++) {
		cin >> v1 >> v2;
		AdjList[v1].push_back(v2);
		AdjList[v2].push_back(v1);
	}

	// DFS 탐색
	bool isAns = false;
	for (int i = 0; i < N; i++) {
		Visited[i] = true;
		isAns = DFS(0, i);
		Visited[i] = false;
		if (isAns) break;
	}

	// 정답 출력
	if (isAns) cout << 1;
	else cout << 0;

	return 0;
}