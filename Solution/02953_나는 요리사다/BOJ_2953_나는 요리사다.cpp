#include <iostream>
#define SIZE 5
using namespace std;

int main() {

	// �����ں� ���� �Է�, �ջ�
	int sum[SIZE] = { 0, };
	int score;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> score;
			sum[i] += score;
		}
	}

	// �ִ������� ���� ����� ��ȣ ����
	int num = 0;
	for (int i = 1; i < SIZE; i++) {
		if (sum[num] < sum[i]) num = i;
	}

	// ���� ���
	cout << num + 1<< " " << sum[num];

	return 0;
}