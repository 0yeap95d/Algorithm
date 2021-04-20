#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, w, L, answer;
vector<int> truck;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> n >> w >> L;
	int inp;
	for (int i = 0; i < n; i++) {
		cin >> inp;
		truck.push_back(inp);
	}

	int idx = 0;
	int weight = 0;
	queue<int> que;
	for (int i = 0; i < w; i++) que.push(0);

	while (true) {
		answer++; 
		weight = weight - que.front();
		que.pop();
		
		if (weight + truck[idx] > L) que.push(0);
		else {
			weight = weight + truck[idx];
			que.push(truck[idx++]);
		}

		if (idx == n) break;
	}

	cout << answer + w;

	return 0;
}