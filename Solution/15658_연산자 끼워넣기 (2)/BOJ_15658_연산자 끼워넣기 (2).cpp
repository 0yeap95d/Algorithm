#include <iostream>
#include <algorithm>
#define SIZE 11
#define INF 2000000000
using namespace std;

int N;
int Ans_Max = -INF;
int Ans_Min = INF;
int arr[SIZE], oper[4];

void Calculater(int num, int idx) {

	if (idx >= N) {
		Ans_Max = max(Ans_Max, num);
		Ans_Min = min(Ans_Min, num);
		return;
	}

	// 더하기
	if (oper[0] != 0) {
		oper[0]--;
		Calculater(num + arr[idx], idx + 1);
		oper[0]++;
	}

	// 빼기
	if (oper[1] != 0) {
		oper[1]--;
		Calculater(num - arr[idx], idx + 1);
		oper[1]++;
	}

	// 곱하기
	if (oper[2] != 0) {
		oper[2]--;
		Calculater(num * arr[idx], idx + 1);
		oper[2]++;
	}

	// 나누기
	if (oper[3] != 0) {
		oper[3]--;
		Calculater(num / arr[idx], idx + 1);
		oper[3]++;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// 입력
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	for (int i = 0; i < 4; i++) cin >> oper[i];

	// 백트래킹
	Calculater(arr[0], 1);

	// 출력
	cout << Ans_Max << "\n" << Ans_Min;

	return 0;
}