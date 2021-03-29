#include <iostream>
#include <queue>
#include <vector>
#define MAX_SIZE 1001
#define MAX_VAL 987654321
using namespace std;

struct Data {
	int sp;
	int ep;
	int time;
};

bool operator < (Data d1, Data d2) {
	return d1.time > d2.time;
}

int N, M, X;
int road[MAX_SIZE][MAX_SIZE];
int ansSE[MAX_SIZE], ansES[MAX_SIZE];

int findRoad(int start, int end) {

	priority_queue<Data> pq;
	vector<int> value(N + 1, MAX_VAL);
	
	pq.push({ 0, start, 0 });
	value[start] = 0;

	while (!pq.empty()) {
		Data data = pq.top();
		pq.pop();

		if (data.ep == end) return data.time;

		for (int i = 1; i <= N; i++) {
			if (road[data.ep][i] == 0) continue;
			else if (value[i] < data.time + road[data.ep][i]) continue;
			pq.push({ data.ep, i, data.time + road[data.ep][i] });
			value[i] = data.time + road[data.ep][i];
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// 마을 수 N, 도로 수 M, 파티장소 X 입력
	cin >> N >> M >> X;

	// 도로 정보 입력
	int sp, ep, t;
	for (int i = 0; i < M; i++) {
		cin >> sp >> ep >> t;
		road[sp][ep] = t;
	}

	// 각 마을에서 파티장소까지 걸리는 시간
	for (int i = 1; i <= N; i++) {
		if (i == X) continue;
		ansSE[i] = findRoad(i, X);
	}

	// 파티장소에서 각 마을까지 걸리는 시간
	for (int i = 1; i <= N; i++) {
		if (i == X) continue;
		ansES[i] = findRoad(X, i);
	}

	// 정답 출력
	int ans = 0;
	for (int i = 1; i <= N; i++) 
		ans = max(ans, ansSE[i] + ansES[i]);
	
	cout << ans;

	return 0;
}