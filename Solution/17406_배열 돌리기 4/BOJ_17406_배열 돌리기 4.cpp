#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 987654321
using namespace std;

int N, M, K;
vector<vector<int>> inp;
vector<vector<int>> com;

int getMinSum(vector<vector<int>> &data) {
	int ret = MAX;
	for (int i = 0; i < N; i++) {
		int sum = 0;
		for (int j = 0; j < M; j++) sum += data[i][j];
		ret = min(ret, sum);
	}
	return ret;
}

void rotationArr(int idx, vector<vector<int>> &data) {
	for (int i = 1; i <= com[idx][2]; i++) {
		pair<int, int> start(com[idx][0] - i, com[idx][1] - i);
		int x = start.first;
		int y = start.second;
		int pre = data[x][y];
		int dir = 0;
		while (1) {
			if (dir == 0) {
				y++;
				int temp = data[x][y];
				data[x][y] = pre;
				pre = temp;
				if (y + 1 > com[idx][1] + i) { dir++; continue; }
				//else y++;
			}
			else if (dir == 1) {
				x++;
				int temp = data[x][y];
				data[x][y] = pre;
				pre = temp;
				if (x + 1 > com[idx][0] + i) { dir++; continue; }
				//else x++;
			}
			else if (dir == 2) {
				y--;
				int temp = data[x][y];
				data[x][y] = pre;
				pre = temp;
				if (y - 1 < com[idx][1] - i) { dir++; continue; }
				//else y--;
			}
			else {
				x--;
				int temp = data[x][y];
				data[x][y] = pre;
				pre = temp;
				if (x - 1 < com[idx][0] - i) break;
				//else x--;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;
	inp.assign(N, vector<int>(M, 0));
	com.assign(K, vector<int>(3, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cin >> inp[i][j];
	}

	for (int i = 0; i < K; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> com[i][j];
			if (j < 2) com[i][j]--;
		}
	}
	
	vector<int> order;
	for (int i = 0; i < K; i++) order.push_back(i);

	int ans = MAX;
	do {
		vector<vector<int>> copyArr;
		copyArr.assign(inp.begin(), inp.end());
		for (int i = 0; i < order.size(); i++) {
			rotationArr(order[i], copyArr);
		}
		ans = min(ans, getMinSum(copyArr));
	} while (next_permutation(order.begin(), order.end()));

	cout << ans;

	return 0;
}