#include <iostream>
#include <algorithm>
#include <cstring>
#define SIZE 21
#define INF 987654321
using namespace std;

int N, Ans = INF;
int Area[SIZE][SIZE];
bool isJHArea[SIZE][SIZE];
int Population[5];

// 재현시 구역 지정하기
void setJHArea(int x, int y, int d1, int d2) {
	bool addLeft = false;
	bool addRight = true;

	int left, right;
	left = right = y;
	
	memset(isJHArea, false, sizeof(isJHArea));

	while (left <= right) {
		for (int i = left; i <= right; i++) isJHArea[x][i] = true;
		
		if (left == y - d1) addLeft = !addLeft;
		if (right == y + d2) addRight = !addRight;
		
		if (addLeft) left++;
		else left--;

		if (addRight) right++;
		else right--;

		x++;
	}
}

// 각 구역 인원 구하기
void sumPopulation(int x, int y, int d1, int d2) {
	int idx = -1;
	for (int i = 0; i < 5; i++) Population[i] = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			if (isJHArea[i][j]) idx = 0;	// 재현시 구역
			else if (i < x + d1 && j <= y) idx = 1;	// 1번 구역
			else if (i <= x + d2 && y < j) idx = 2;	// 2번 구역
			else if (x + d1 <= i && j < y - d1 + d2) idx = 3;	// 3번 구역
			else if (x + d2 < i && y - d1 + d2 <= j) idx = 4;	// 4번 구역 
			
			Population[idx] += Area[i][j];
		}
	}
}

int getMinDif() {
	int maxVal, minVal;
	maxVal = minVal = Population[0];

	for (int i = 1; i < 5; i++) {
		maxVal = max(maxVal, Population[i]);
		minVal = min(minVal, Population[i]);
	}

	return maxVal - minVal;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Area[i][j];
		}
	}

	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			for (int d1 = 1; d1 < N; d1++) {
				if (y - d1 < 0) break;
				for (int d2 = 1; d2 < N; d2++) {
					if (x + d1 + d2 >= N || y + d2 >= N) break;
					setJHArea(x, y, d1, d2);
					sumPopulation(x, y, d1, d2);
					Ans = min(Ans, getMinDif());
				}
			}
		}
	}

	cout << Ans;

	return 0;
}