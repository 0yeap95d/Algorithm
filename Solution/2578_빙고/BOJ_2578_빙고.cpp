#include <iostream>
#define SIZE 5
using namespace std;

int bingo[SIZE][SIZE];

// �ش� ���� �����
void deleteNum(int num) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (bingo[i][j] == num) {
				bingo[i][j] = 0;
				return;
			}
		}
	}
}

// �������� �ƴ��� Ȯ��
bool isBingo() {
	int n = 0;
	bool ret = false;

	// ���� Ȯ��
	for (int i = 0; i < SIZE; i++) {
		bool isCorrect = true;
		for (int j = 0; j < SIZE; j++) {
			if (bingo[i][j] != 0) {
				isCorrect = false;
				break;
			}
		}
		if (isCorrect) n++;
	}

	// ���� Ȯ��
	for (int i = 0; i < SIZE; i++) {
		bool isCorrect = true; 
		for (int j = 0; j < SIZE; j++) {
			if (bingo[j][i] != 0) {
				isCorrect = false;
				break;
			}
		}
		if (isCorrect) n++;
	}

	// �밢�� Ȯ��
	bool isCorrect = true;
	for (int i = 0; i < SIZE; i++) {
		if (bingo[i][i] != 0) {
			isCorrect = false;
			break;
		}
	}
	if (isCorrect) n++;

	isCorrect = true;
	for (int i = 0; i < SIZE; i++) {
		if (bingo[i][SIZE - i - 1] != 0) {
			isCorrect = false;
			break;
		}
	}
	if (isCorrect) n++;

	if (n >= 3) ret = true;
	return ret;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// ö�� ���� �Է�
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cin >> bingo[i][j];
		}
	}

	// ���� �θ���
	int num;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cin >> num;
			deleteNum(num);
			if (isBingo()) {
				cout << i * SIZE + j + 1;
				return 0;
			}
		}
	}

	return 0;
}