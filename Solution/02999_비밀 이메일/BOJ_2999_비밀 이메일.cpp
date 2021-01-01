#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 문자열 입력
	string inp;
	cin >> inp;

	// 입력받은 문자열의 크기
	int N = inp.size();

	// R, C 고르기 ( R <= C && R * C = N )
	int R, C;
	for (int i = 1; i <= sqrt(N); i++) {
		if (N % i == 0) {
			R = i;
			C = N / i;
		}
	}

	// 문자열 R X C 배열에 담기
	vector<vector<char>> arr(R, vector<char>(C, ' '));
	int idx = 0;
	for (int i = 0; i < C; i++) {
		for (int j = 0; j < R; j++) {
			arr[j][i] = inp[idx++];
		}
	}

	// 문자열 출력
	string ans;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			ans += arr[i][j];
		}
	}
	cout << ans;

	return 0;
}