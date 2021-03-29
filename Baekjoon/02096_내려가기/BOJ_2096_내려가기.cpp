#include <iostream>
#include <algorithm>
using namespace std;

int inp[3], max_point[3], min_point[3], pre_max[3], pre_min[3];

int main() {
	int n, out1, out2;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> inp[0] >> inp[1] >> inp[2];

		max_point[0] = inp[0] + max(pre_max[0], pre_max[1]);
		max_point[1] = inp[1] + max(max(pre_max[0], pre_max[1]), pre_max[2]);
		max_point[2] = inp[2] + max(pre_max[1], pre_max[2]);
	
		for (int j = 0; j < 3; j++) pre_max[j] = max_point[j];

		min_point[0] = inp[0] + min(pre_min[0], pre_min[1]);
		min_point[1] = inp[1] + min(min(pre_min[0], pre_min[1]), pre_min[2]);
		min_point[2] = inp[2] + min(pre_min[1], pre_min[2]);
		for (int j = 0; j < 3; j++) pre_min[j] = min_point[j];
	}
	out1 = max(max(pre_max[0], pre_max[1]), pre_max[2]);
	out2 = min(min(pre_min[0], pre_min[1]), pre_min[2]);
	cout << out1 << " " << out2;
	return 0;
}