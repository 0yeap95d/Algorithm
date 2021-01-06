#include <iostream>
#include <vector>
#include <map>
using namespace std;

int N;
vector<int> P, card;
map<int, int> S;

// ī�� ����
void mixCard() {
	for (int i = 0; i < N; i++) card[i] = S[card[i]];
}

// �ش� ī�尡 �� �÷��̾�� ���ư��� ��
bool isAns() {
	bool ret = true;
	for (int i = 0; i < N; i++) {
		if (card[i] % 3 == P[i]) continue;
		ret = false;
		break;
	}
	return ret;
}

// ī�尡 ó�� ���·� ������ ��
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

	// ī���� ���� N �Է�
	cin >> N;
	P.assign(N, 0);
	card.assign(N, 0);

	// �� �÷��̾ �޾ƾ��ϴ� ī�� ���� P �Է�, ī�� ����
	for (int i = 0; i < N; i++) {
		cin >> P[i];
		card[i] = i;
	}

	// ���� �� ī���� ��ġ
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

	// ���� ���
	cout << ans;

	return 0;
}