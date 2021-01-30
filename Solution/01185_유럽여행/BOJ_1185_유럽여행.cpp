#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define SIZE 10001
using namespace std;

struct cmp {
	bool operator()(pair<int, int> p1, pair<int, int> p2) {
		if (p1.second == p2.second) return p1.first > p2.first;
		return p1.second > p2.second;
	}
};

int N, P, Min_Country = SIZE;
long long Ans;
int Country[SIZE];
bool Visited[SIZE];
vector<pair<int, int>> Path[SIZE];
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> Trip;


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> P;
	for (int i = 1; i <= N; i++) {
		cin >> Country[i];
		Min_Country = min(Min_Country, Country[i]);
	}

	int v1, v2, cost;
	for (int i = 0; i < P; i++) {
		cin >> v1 >> v2 >> cost;
		Path[v1].push_back({ v2, cost });
		Path[v2].push_back({ v1, cost });
	}

	Trip.push({ 1, 0 });
	while (!Trip.empty()) {
		v1 = Trip.top().first;
		cost = Trip.top().second;
		Trip.pop();

		if (Visited[v1]) continue;

		Ans = Ans + (long long)cost;
		Visited[v1] = true;

		for (auto path : Path[v1]) {
			v2 = path.first;
			if (Visited[v2]) continue;
			cost = Country[v1] + Country[v2] + (path.second * 2);
			Trip.push({ v2, cost });
		}
	}

	cout << Ans + (long long)Min_Country;

	return 0;
}