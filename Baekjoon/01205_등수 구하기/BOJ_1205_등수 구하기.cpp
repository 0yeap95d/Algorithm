#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, S, P;
vector<int> score;
vector<int> rankList;

void init() {
	// N: ������ ����, S: �������� ����, P: ����Ʈ ũ��
	cin >> N >> S >> P;

	int rank;
	for (int i = 0; i < N; i++) {
		cin >> rank;
		score.push_back(rank);
	}
	score.push_back(S);
}

void setRank() {	// ���� �ű��
	for (int i = 0; i < score.size(); i++) {
		if (i >= P) rankList.push_back(-1);
		else if (i == 0) rankList.push_back(i + 1);
		else if (score[i] == score[i - 1]) rankList.push_back(rankList[i - 1]);
		else rankList.push_back(i + 1);
	}
}

int getRank() {		// ������ ��ŷ ã��
	for (int i = N; i >= 0; i--) {
		if (score[i] == S) return rankList[i];
	}
}

int main() {

	init();
	sort(score.begin(), score.end(), greater<int>());
	setRank();
	cout << getRank();

	return 0;
}