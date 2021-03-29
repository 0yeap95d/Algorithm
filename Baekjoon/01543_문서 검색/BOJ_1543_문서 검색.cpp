#include <iostream>
#include <string>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// ���� doc, �ܾ� word �Է�
	string doc, word;
	getline(cin, doc);
	getline(cin, word);

	if (doc.size() < word.size()) {
		cout << 0;
		return 0;
	}

	int ans = 0;
	for (int i = 0; i <= doc.size() - word.size(); i++) {
	
		bool isSame = true;
	
		// ���ڿ� ��
		for (int j = 0; j < word.size(); j++) {
			if (doc[i + j] != word[j]) {
				isSame = false;
				break;
			}
		}

		// ���ٸ� ���� �ε������� ����
		if (isSame) {
			ans++;
			i += word.size() - 1;
		}
	}

	// ���� ���
	cout << ans;

	return 0;
}