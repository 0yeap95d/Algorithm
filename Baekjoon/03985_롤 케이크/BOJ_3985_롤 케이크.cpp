#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 롤 케이크 길이 입력
	int L = 0;
	cin >> L;
	vector<int> cake(L + 1, 0);

	// 참가자 수
	int N = 0;
	cin >> N;

	// 참가자별 롤 케이크 받는 조각
	int P, K;
	int val1, val2, ans1, ans2;
	val1 = val2 = ans1 = ans2 = 0;
	for (int i = 1; i < N + 1; i++) {
		cin >> P >> K;
		
		int num = K - P + 1;

		// 가장 많은 조각을 받을 것으로 기대하고 있던 방청객 번호
		if (val1 < num) {
			ans1 = i;
			val1 = num;
		}

		// 실제 케이크 누가 가져가는지 체크
		for (int idx = P; idx <= K; idx++) {
			if (cake[idx] == 0) cake[idx] = i;
			else num--;
		}

		// 실제 가장 많은 조각을 받는 방청객 번호
		if (val2 < num) {
			ans2 = i;
			val2 = num;
		}
	}

	// 결과 출력
	cout << ans1 << "\n" << ans2;

	return 0;
}