#include <iostream>
using namespace std;

bool plane[100][100];

// ��鿡 �Է¹��� ���簢�� ä���
void setRec(int lx, int ly, int rx, int ry) {
	for (int x = lx; x < rx; x++) {
		for (int y = ly; y < ry; y++) {
			plane[x][y] = true;
		}
	}
}

// ��ĥ�Ǿ��ִ� ���� ī��Ʈ
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