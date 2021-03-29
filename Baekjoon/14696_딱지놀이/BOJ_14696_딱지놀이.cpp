#include <iostream>
#include <string.h>
using namespace std;

/*
조건
1. 만약 두 딱지의 별의 개수가 다르면, 별이 많은 쪽의 딱지가 이긴다
2. 별의 개수가 같고 동그라미 개수가 다르면, 동그라미 많은 쪽의 딱지가 이긴다
3. ... 네모개수가 다르면, 네모 많은 쪽
4. ... 세모개수가 다르면, 세모 많은 쪽
5. 모두 같으면 무승부
*/

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// 총 라운드 수 입력
	int N;
	cin >> N;

	// A, B의 그림의 총 개수 a, b
	int a, b, inp;
	int picture[2][5];
	char ans;

	for (int i = 0; i < N; i++) {
		// 딱지 정보 초기화
		memset(picture, 0, sizeof(picture));

		// A의 딱지 정보 입력
		cin >> a;
		for (int j = 0; j < a; j++) {
			cin >> inp;
			picture[0][inp]++;
		}

		// B의 딱지 정보 입력
		cin >> b;
		for (int j = 0; j < b; j++) {
			cin >> inp;
			picture[1][inp]++;
		}

		// A, B 승패 비교
		ans = 'D';
		for (int j = 4; j >= 1; j--) {
			if (picture[0][j] > picture[1][j]) {
				ans = 'A';
				break;
			}
			else if (picture[0][j] < picture[1][j]) {
				ans = 'B';
				break;
			}
		}
		cout << ans << "\n";
	}
	
	return 0; 
}