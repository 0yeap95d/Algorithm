#include <iostream>
#include <vector>
#define SIZE 1001
using namespace std;

int V, E, Ans;
vector<vector<int>> Graph;
bool Visit[SIZE];

int DFS(int idx) {
	int odd = 0;
	if ((Graph[idx].size() % 2) != 0) odd++;
	
	for (auto v : Graph[idx]) {
		if (Visit[v]) continue;
		Visit[v] = true;
		odd = odd + DFS(v);
	}
	
	return odd;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> V >> E;

	// 그래프 입력
	int v1, v2;
	Graph.resize(V + 1);
	for (int i = 0; i < E; i++) {
		cin >> v1 >> v2;
		Graph[v1].push_back(v2);
		Graph[v2].push_back(v1);
	}

	// 분리된 그래프를 
	for (int i = 1; i <= V; i++) {
		if (Visit[i]) continue;
		Visit[i] = true;
		
		// 분리된 그래프를 연결하는데 필요한 간선 추가 (출력 시 -1)
		Ans++;

		// 각 분리된 그래프를 한붓그리기 가능하게 만들기 위해 필요한 간선 추가
		int countOdd = DFS(i);
		if (countOdd > 2) Ans += (countOdd - 2) / 2;
	}

	cout << Ans - 1;

	return 0;
}