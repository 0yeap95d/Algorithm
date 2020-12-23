#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 돌 개수 입력
	int N;
	cin >> N;

	// 돌의 개수가 홀수면 상근이 승리, 짝수면 창영이 승리
	if (N % 2 == 1) cout << "SK";
	else cout << "CY";

	return 0;
}