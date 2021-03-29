#include <iostream>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// 너비 w, 높이 h, 개미위치 (x, y), 이동시간 t
	int w, h, x, y, t;
	cin >> w >> h >> x >> y >> t;

	// 개미 이동
	int dx, dy;
	dx = dy = 1;
	if (((t + x) / w) % 2 != 0) dx = -dx;
	if (((t + y) / h) % 2 != 0) dy = -dy;

	if (dx > 0) x = (t + x) % w;
	else x = w - (t + x) % w;

	if (dy > 0) y = (t + y) % h;
	else y = h - (t + y) % h;


	// 개미 위치 출력
	cout << x << " " << y;

	return 0;
}