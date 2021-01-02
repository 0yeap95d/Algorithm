#include <iostream>
#include <string.h>
using namespace std;

/*
����
1. ���� �� ������ ���� ������ �ٸ���, ���� ���� ���� ������ �̱��
2. ���� ������ ���� ���׶�� ������ �ٸ���, ���׶�� ���� ���� ������ �̱��
3. ... �׸𰳼��� �ٸ���, �׸� ���� ��
4. ... ���𰳼��� �ٸ���, ���� ���� ��
5. ��� ������ ���º�
*/

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// �� ���� �� �Է�
	int N;
	cin >> N;

	// A, B�� �׸��� �� ���� a, b
	int a, b, inp;
	int picture[2][5];
	char ans;

	for (int i = 0; i < N; i++) {
		// ���� ���� �ʱ�ȭ
		memset(picture, 0, sizeof(picture));

		// A�� ���� ���� �Է�
		cin >> a;
		for (int j = 0; j < a; j++) {
			cin >> inp;
			picture[0][inp]++;
		}

		// B�� ���� ���� �Է�
		cin >> b;
		for (int j = 0; j < b; j++) {
			cin >> inp;
			picture[1][inp]++;
		}

		// A, B ���� ��
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