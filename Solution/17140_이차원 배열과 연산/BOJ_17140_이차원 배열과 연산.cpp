#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
#define SIZE 101
using namespace std;

int R, C, K;
int width, height;
int Arr[SIZE][SIZE];

void funcR() {
	map<int, int> idxMap;
	vector<pair<int, int>> vec[SIZE];

	int maxWidth = 0;

	// 정렬
	for (int i = 0; i < height; i++) {
		idxMap.clear();

		for (int j = 0; j < width; j++) {
			int value = Arr[i][j];
			int idx = idxMap[value] - 1;
			
			if (value == 0) continue;

			// 처음 들어온 값
			if (idx == -1) {
				vec[i].push_back({1, value});
				idxMap[value] = vec[i].size();
			}

			// 이미 존재하는 값
			else vec[i][idx].first++;
		}
		maxWidth = max(maxWidth, (int)vec[i].size() * 2);
		sort(vec[i].begin(), vec[i].end());
	}
	width = maxWidth;

	// 배열 재생성
	memset(Arr, 0, sizeof(Arr));
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			if (j >= 50) break;
			Arr[i][j * 2] = vec[i][j].second;
			Arr[i][j * 2 + 1] = vec[i][j].first;
		}
	}
}

void funcC() {
	map<int, int> idxMap;
	vector<pair<int, int>> vec[SIZE];

	int maxHeight = 0;

	// 정렬
	for (int i = 0; i < width; i++) {
		idxMap.clear();

		for (int j = 0; j < height; j++) {
			int value = Arr[j][i];
			int idx = idxMap[value] - 1;

			if (value == 0) continue;

			// 처음 들어온 값
			if (idx == -1) {
				vec[i].push_back({ 1, value });
				idxMap[value] = vec[i].size();
			}

			// 이미 존재하는 값
			else vec[i][idx].first++;
		}
		maxHeight = max(maxHeight, (int)vec[i].size() * 2);
		sort(vec[i].begin(), vec[i].end());
	}

	height = maxHeight;

	// 배열 재생성
	memset(Arr, 0, sizeof(Arr));
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			if (j >= 50) break;
			Arr[j * 2][i] = vec[i][j].second;
			Arr[j * 2 + 1][i] = vec[i][j].first;
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> R >> C >> K;
	width = height = 3;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> Arr[i][j];
		}
	}

	int time = 0;
	while (time <= 100) {
		if (Arr[R - 1][C - 1] == K) break;
		if (height >= width) funcR();
		else funcC();
		time++;
	}

	if (time > 100) cout << -1;
	else cout << time;

	return 0;
}