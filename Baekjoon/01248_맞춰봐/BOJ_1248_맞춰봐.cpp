#include <iostream>
#define SIZE 10
using namespace std;

int N, Ans[SIZE];
int S[SIZE][SIZE];

// ���� i���� j�� ������ ��
int sumArr(int sp, int ep) {
	int result = 0;
	for (int i = sp; i <= ep; i++) result = result + Ans[i];
	return result;
}

// ��� ������ �����ϴ��� üũ
bool isPossible(int idx) {
	for (int i = 0; i < idx; i++) {
		int sum = sumArr(i, idx);
		if ((S[i][idx] == 1 && sum <= 0) || (S[i][idx] == -1 && sum >= 0) || (S[i][idx] == 0 && sum != 0)) 
			return false;
	}
	return true;
}

bool Search(int idx) {

	if (idx >= N) {
		for (int i = 0; i < N; i++) cout << Ans[i] << " ";
		return true;
	}

	if (S[idx][idx] == 1) {
		for (int i = 1; i <= 10; i++) {
			Ans[idx] = i;
			if (isPossible(idx) && Search(idx + 1)) return true;
		}
	}
	else if (S[idx][idx] == -1) {
		for (int i = -1; i >= -10; i--) {
			Ans[idx] = i;
			if (isPossible(idx) && Search(idx + 1)) return true;
		}
	}
	else {
		Ans[idx] = 0;
		return Search(idx + 1);
	}

	return false;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// �Է�
	cin >> N;
	char ch;
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			cin >> ch;
			if (ch == '+') S[i][j] = 1;
			else if (ch == '-') S[i][j] = -1;
			else S[i][j] = 0;
		}
	}

	Search(0);

	return 0;
}