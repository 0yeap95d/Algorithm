#include <iostream>
#include <algorithm>
#define SIZE 10001
using namespace std;

int N;
int arr[SIZE];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N;

	// ���� �Է�
	for (int i = 0; i < N; i++) cin >> arr[i];
	
	// ������ �ڿ��� ���� ��
	bool isAns = false;
	for (int i = N - 2; i >= 0; i--) {
		if (arr[i] < arr[i + 1]) continue;

		int val, idx, temp;
		val = idx = -1;
		for (int j = i + 1; j < N; j++) {
			if (arr[i] < arr[j] || val > arr[j]) continue;
			val = arr[j];
			idx = j;
		}

		temp = arr[i];
		arr[i] = arr[idx];
		arr[idx] = temp;

		reverse(arr + i + 1, arr + N);
		isAns = true;
		break; 
	}

	// ���� ������ ���� ��
	if (!isAns) cout << -1;

	// ���� ������ ���� ��
	else {
		for (int i = 0; i < N; i++) 
			cout << arr[i] << " ";
	}
	return 0;
}