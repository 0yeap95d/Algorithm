#include <iostream>
#define SIZE 100001
using namespace std;

int N, M;
int Arr[SIZE];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// 입력 & 누적 합
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> Arr[i];
		Arr[i] = Arr[i] + Arr[i - 1];
	}

	// 정답 출력
	int start, end;
	while (M--) {
		cin >> start >> end;
		cout << Arr[end] - Arr[start - 1] << "\n";
	}

	return 0;
}