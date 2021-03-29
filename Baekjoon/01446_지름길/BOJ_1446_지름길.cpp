#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Short {
	int start;
	int end;
	int dis;
};

bool operator<(Short s1, Short s2) {
	if (s1.start == s2.start) return s1.end > s2.end;
	return s1.start > s2.start;
}

int N, D;
int road[10001];
priority_queue<Short> pq;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// 지름길의 개수 N, 고속도로의 길이 D
	cin >> N >> D;

	int start, end, time;
	for (int i = 0; i < N; i++) {
		cin >> start >> end >> time;
		if (end > D) continue;
		pq.push({ start, end, time });
	}

	for (int i = 0; i <= D; i++) road[i] = i;

	for (int i = 0; i <= D; i++) {
		
		// 각 위치까지의 최소값 설정
		if (road[i] != 0) road[i] = min(road[i - 1] + 1, road[i]);
		else if (i != 0) road[i] = road[i - 1];

		while (!pq.empty() && pq.top().start == i) {
			Short s = pq.top();
			pq.pop();
			road[s.end] = min(road[s.end], road[s.start] + s.dis);
		}
	}

	// 정답 출력
	cout << road[D];

	return 0;
}