#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int C, ans;
int stats[11][11];
bool player[11];

int setPlayer(int pos, int sum) {

	// 모든 선수가 포지션에 배치되었을 때
	if (pos == 11) return sum;

	int ret = 0;
	bool isSet = false;
	for (int i = 0; i < 11; i++) {
		// 이미 배치된 선수 또는 해당 포지션에 적합하지 않는 선수
		if (player[i] || stats[i][pos] == 0) continue;

		// pos번 포지션에 i 선수 배치
		isSet = true;
		player[i] = true;
		ret = max(ret, setPlayer(pos + 1, sum + stats[i][pos]));
		player[i] = false;
	}

	// pos번에 적합한 선수가 한명도 없다면 리턴
	if (!isSet) return 0;

	// 아니면 능력치의 최대값 리턴
	else return ret;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// 테스트 케이스 C 입력
	cin >> C;

	while (C--) {
		// 능력치 입력
		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 11; j++) {
				cin >> stats[i][j];
			}
		}

		// 선수 배치 및 정답출력
		cout << setPlayer(0, 0) << "\n";
	}

	return 0;
}