#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string.h>
#define SIZE 10
using namespace std;

int paper[SIZE][SIZE];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int x, y, p, q;
	int a, b, c, d;

	for (int i = 0; i < 4; i++) {
		memset(paper, 0, sizeof(paper));

		// 직사각형 두개 입력
		cin >> x >> y >> p >> q;
		cin >> a >> b >> c >> d;
		
		// x좌표 정렬
		vector<int> tempX;
		tempX.push_back(x);
		tempX.push_back(p);
		tempX.push_back(a);
		tempX.push_back(c);
		sort(tempX.begin(), tempX.end());

		// x좌표 압축
		map<int, int> mapX;
		int num = 1;
		for (int i : tempX) if (mapX[i] == 0) mapX[i] = num++;
		x = mapX[x];
		p = mapX[p];
		a = mapX[a];
		c = mapX[c];

		// y좌표 정렬
		vector<int> tempY;
		tempY.push_back(y);
		tempY.push_back(q);
		tempY.push_back(b);
		tempY.push_back(d);
		sort(tempY.begin(), tempY.end());

		// y좌표 압축
		map<int, int> mapY;
		num = 1;
		for (int i : tempY) if (mapY[i] == 0) mapY[i] = num++;
		y = mapY[y];
		q = mapY[q];
		b = mapY[b];
		d = mapY[d];

		// 종이에 압축된 첫번째 직사각형 색칠
		for (int i = x; i <= p; i++) {
			for (int j = y; j <= q; j++) {
				paper[i][j] += 1;
			}
		}

		// 종이에 압축된 두번째 직사각형 색칠
		for (int i = a; i <= c; i++) {
			for (int j = b; j <= d; j++) {
				paper[i][j] += 2;
			}
		}

		// 공통부분 너비, 높이 구하기
		int width, height, ws, we, hs, he;
		width = height = ws = we = hs = he = 0;
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				if (paper[i][j] == 3) {
					if (ws == 0) ws = i;
					we = i;

					if (hs == 0) hs = j;
					he = j;
				}
			}
		}
		
		if (ws == 0) width = 0;
		else if (ws == we) width = 1;
		else width = we - ws + 1;

		if (hs == 0) height = 0;
		else if (hs == he) height = 1;
		else height = he - hs + 1;

		// 겹치는 부분 판별
		if (width == 0 && height == 0) cout << "d" << "\n";
		else if (width == 1 && height == 1) cout << "c" << "\n";
		else if (width == 1 || height == 1) cout << "b" << "\n";
		else cout << "a" << "\n";
	}

	return 0;
}