#include <iostream>
#include <vector>
#include <map>
using namespace std;

int N;
vector<int> P, card;
map<int, int> S;

// 카드 섞기
void mixCard() {
	for (int i = 0; i < N; i++) card[i] = S[card[i]];
}

// 해당 카드가 각 플레이어에게 돌아갔을 때
bool isAns() {
	bool ret = true;
	for (int i = 0; i < N; i++) {
		if (card[i] % 3 == P[i]) continue;
		ret = false;
		break;
	}
	return ret;
}

// 카드가 처음 상태로 돌아을 때
bool isFail() {
	bool ret = true;
	for (int i = 0; i < N; i++) {
		if (card[i] == i) continue;
		ret = false;
		break;
	}
	return ret;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// 카드의 개수 N 입력
	cin >> N;
	P.assign(N, 0);
	card.assign(N, 0);

	// 각 플레이어가 받아야하는 카드 정보 P 입력, 카드 셋팅
	for (int i = 0; i < N; i++) {
		cin >> P[i];
		card[i] = i;
	}

	// 섞을 때 카드의 위치
	int num;
	for (int i = 0; i < N; i++) cin >> S[i];
	

	int ans = 0;
	while(1) {
		if (isAns()) break;
		mixCard();
		ans++;
		if (isFail()) {
			ans = -1; 
			break;
		}
	}

	// 정답 출력
	cout << ans;

	return 0;
}