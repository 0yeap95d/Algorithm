#include <iostream>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// �ʺ� w, ���� h, ������ġ (x, y), �̵��ð� t
	int w, h, x, y, t;
	cin >> w >> h >> x >> y >> t;

	// ���� �̵�
	int dx, dy;
	dx = dy = 1;
	if (((t + x) / w) % 2 != 0) dx = -dx;
	if (((t + y) / h) % 2 != 0) dy = -dy;

	if (dx > 0) x = (t + x) % w;
	else x = w - (t + x) % w;

	if (dy > 0) y = (t + y) % h;
	else y = h - (t + y) % h;


	// ���� ��ġ ���
	cout << x << " " << y;

	return 0;
}