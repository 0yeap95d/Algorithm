#include <iostream>
#define SIZE 5
using namespace std;

int main() {

	// 참가자별 점수 입력, 합산
	int sum[SIZE] = { 0, };
	int score;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> score;
			sum[i] += score;
		}
	}

	// 최대점수를 받은 사람의 번호 갱신
	int num = 0;
	for (int i = 1; i < SIZE; i++) {
		if (sum[num] < sum[i]) num = i;
	}

	// 정답 출력
	cout << num + 1<< " " << sum[num];

	return 0;
}