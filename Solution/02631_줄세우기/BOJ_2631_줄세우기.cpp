#include <iostream>
using namespace std;

int main() {
	int num;
	cin >> num;

	int arr[1001][2] = { 0, };
	for (int i = 0; i < num; i++) {
		cin >> arr[i][0];
	}

	int max, out = 1;
	for (int i = 0; i < num; i++) {
		max = 0;
		for (int j = 0; j < i; j++) {
			if (arr[i][0] <= arr[j][0]) continue;
			else {
				if (max < arr[j][1]) max = arr[j][1];
			}
		}
		arr[i][1] = max + 1;
		if (arr[i][1] > out) out = arr[i][1];
	}

	cout << num - out;

	return 0;
}