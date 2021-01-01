#include <iostream>
using namespace std;

bool plane[100][100];

// 평면에 입력받은 직사각형 채우기
void setRec(int lx, int ly, int rx, int ry) {
	for (int x = lx; x < rx; x++) {
		for (int y = ly; y < ry; y++) {
			plane[x][y] = true;
		}
	}
}

// 색칠되어있는 면적 카운트
int getArea() {
	int ret = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) 
			if (plane[i][j]) ret++;
	}
	return ret;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int lx, ly, rx, ry;
	for (int i = 0; i < 4; i++) {
		cin >> lx >> ly >> rx >> ry;
		setRec(lx, ly, rx, ry);
	}

	cout << getArea();

	return 0;
}