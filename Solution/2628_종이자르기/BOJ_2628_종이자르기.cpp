#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int col, row, N;
	cin >> col >> row >> N;
	
	vector<int> width, height;
	width.push_back(0);
	width.push_back(col);
	height.push_back(0);
	height.push_back(row);
	
	int dir, pos;
	for (int i = 0; i < N; i++) {
		cin >> dir >> pos;
		if (dir == 0) height.push_back(pos);
		else width.push_back(pos);
	}

	sort(width.begin(), width.end());
	sort(height.begin(), height.end());

	int w, h, ans;
	w = h = ans = 0;
	for (int i = 0; i < width.size() - 1; i++) w = max(w, width[i + 1] - width[i]);
	for (int i = 0; i < height.size() - 1; i++) h = max(h, height[i + 1] - height[i]);

	cout << w * h;

	return 0;
}