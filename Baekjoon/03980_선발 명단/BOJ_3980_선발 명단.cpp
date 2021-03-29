#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int C, ans;
int stats[11][11];
bool player[11];

int setPlayer(int pos, int sum) {

	// ��� ������ �����ǿ� ��ġ�Ǿ��� ��
	if (pos == 11) return sum;

	int ret = 0;
	bool isSet = false;
	for (int i = 0; i < 11; i++) {
		// �̹� ��ġ�� ���� �Ǵ� �ش� �����ǿ� �������� �ʴ� ����
		if (player[i] || stats[i][pos] == 0) continue;

		// pos�� �����ǿ� i ���� ��ġ
		isSet = true;
		player[i] = true;
		ret = max(ret, setPlayer(pos + 1, sum + stats[i][pos]));
		player[i] = false;
	}

	// pos���� ������ ������ �Ѹ� ���ٸ� ����
	if (!isSet) return 0;

	// �ƴϸ� �ɷ�ġ�� �ִ밪 ����
	else return ret;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// �׽�Ʈ ���̽� C �Է�
	cin >> C;

	while (C--) {
		// �ɷ�ġ �Է�
		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 11; j++) {
				cin >> stats[i][j];
			}
		}

		// ���� ��ġ �� �������
		cout << setPlayer(0, 0) << "\n";
	}

	return 0;
}