#include <iostream>
#include <map>
#include <algorithm>
#define SIZE 3001
using namespace std;

typedef pair<int, int> pii;

int N;
int parents[SIZE];
pair<pii, pii> seg[SIZE];


void Init() {
	cin >> N;
	int sx, sy, ex, ey;
	for (int i = 0; i < N; i++) {
		cin >> sx >> sy >> ex >> ey;
		seg[i] = { {sx, sy}, {ex, ey} };
		parents[i] = i;
	}
}

int ccw(pii a, pii b, pii c) {
	int op = a.first * b.second + b.first * c.second + c.first * a.second;
	op -= a.second * b.first + b.second * c.first + c.second * a.first;

	if (op > 0) return 1;
	else if (op == 0) return 0;
	else return -1;
}

bool isOn(int x, int y) {
	pii a = seg[x].first;
	pii b = seg[x].second;
	pii c = seg[y].first;
	pii d = seg[y].second;

	int ab = ccw(a, b, c) * ccw(a, b, d);
	int cd = ccw(c, d, a) * ccw(c, d, b);

	if (ab == 0 && cd == 0) {
		if (a > b) swap(a, b);
		if (c > d) swap(c, d);
		return c <= b && a <= d;
	}
	return ab <= 0 && cd <= 0;
}

int Find(int x) {
	if (x == parents[x]) return x;
	return parents[x] = Find(parents[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x == y) return;
	parents[x] = y;
}

pii countSet() {
	pii res = { 0, 0 };
	int cnt[SIZE] = { 0, };
	
	for (int i = 0; i < N; i++) {
		int idx = Find(i);
		if (cnt[idx]++ == 0) res.first++;
		res.second = max(res.second, cnt[idx]);
	}
	return res;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	Init();
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (isOn(i, j)) Union(i, j);
		}
	}

	pair<int, int> ans = countSet();
	cout << ans.first << "\n" << ans.second;

	return 0;
}