#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define endl '\n'
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int testCase;
	cin >> testCase;

	int n, k;
	while (testCase--) {
		cin >> n >> k;
		vector<int> weight(n + 1, 0);
		vector<int> count(n + 1, 0);
		vector<vector<int>> adj(n + 1, vector<int>());
		vector<vector<int>> revAdj(n + 1, vector<int>());

		// weight �Է�
		for (int i = 1; i <= n; i++) cin >> weight[i];
		
		// adj, revAdj, count �Է�
		int v1, v2;
		for (int i = 1; i <= k; i++) {
			cin >> v1 >> v2;
			adj[v1].push_back(v2);
			revAdj[v2].push_back(v1);
			count[v2]++;
		}

		// target �Է�
		int target;
		cin >> target;

		// bfs
		queue<int> que;
		
		for (int i = 1; i <= n; i++) {
			if (count[i] != 0) continue;
			bool isAns = false;
			
			que.push(i);
			while (!que.empty()) {
				int top = que.front();
				que.pop();

				// target�� ã���� �ݺ��� ����
				if (top == target) {
					isAns = true;
					break;
				}

				for (int v : adj[top]) {
					count[v]--;
					if (count[v] > 0) continue;

					// revAdj���� �ִ밪 �����ͼ� weight[v]�� �߰�
					int revMax = 0;
					for (int rv : revAdj[v]) revMax = max(weight[rv], revMax);
					
					que.push(v);
					weight[v] += revMax;
				}
			}
			if (isAns) break;
		}
		
		cout << weight[target] << endl;
	}

	return 0;
}