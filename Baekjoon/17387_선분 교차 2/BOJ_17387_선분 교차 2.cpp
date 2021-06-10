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

	// ��� ���� �������� �����ϴ� ���
	if (ab == 0 && cd == 0) {
		if (a > b) swap(a, b);
		if (c > d) swap(c, d);
		return c <= b && a <= d;
	}

	// ab�� cd ��� 0�� ���� ������ ó�����־���
	// ���� ��츦 �����ϰ� ab�� cd�� 0���� �۰ų� ���ٸ� ��������
	return ab <= 0 && cd <= 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	input();
	cout << isCross();

	return 0;
}