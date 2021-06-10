#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

pii a, b, c, d;

void input() {
	int sx, sy, ex, ey;
	cin >> sx >> sy >> ex >> ey;
	a = { sx, sy }, b = { ex, ey };
	cin >> sx >> sy >> ex >> ey;
	c = { sx, sy }, d = { ex, ey };
}

int ccw(pii a, pii b, pii c) {
	int op = a.first * b.second + b.first * c.second + c.first * a.second;
	op -= a.second * b.first + b.second * c.first + c.second * a.first;

	if (op > 0) return 1;
	else if (op == 0) return 0;
	else return -1;
}

bool isCross() {
	int ab = ccw(a, b, c) * ccw(a, b, d);
	int cd = ccw(c, d, a) * ccw(c, d, b);

	// 모든 점이 일직선상에 존재하는 경우
	if (ab == 0 && cd == 0) {
		if (a > b) swap(a, b);
		if (c > d) swap(c, d);
		return c <= b && a <= d;
	}

	// ab와 cd 모두 0인 경우는 위에서 처리해주었음
	// 위의 경우를 제외하고 ab와 cd가 0보다 작거나 같다면 교차상태
	return ab <= 0 && cd <= 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	input();
	cout << isCross();

	return 0;
}