#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// ���ڿ� �Է�
	string inp;
	cin >> inp;

	// �Է¹��� ���ڿ��� ũ��
	int N = inp.size();

	// R, C ���� ( R <= C && R * C = N )
	int R, C;
	for (int i = 1; i <= sqrt(N); i++) {
		if (N % i == 0) {
			R = i;
			C = N / i;
		}
	}

	// ���ڿ� R X C �迭�� ���
	vector<vector<char>> arr(R, vector<char>(C, ' '));
	int idx = 0;
	for (int i = 0; i < C; i++) {
		for (int j = 0; j < R; j++) {
			arr[j][i] = inp[idx++];
		}
	}

	// ���ڿ� ���
	string ans;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			ans += arr[i][j];
		}
	}
	cout << ans;

	return 0;
}