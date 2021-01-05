#include <iostream>
#include <string>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// 문서 doc, 단어 word 입력
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
	
		// 문자열 비교
		for (int j = 0; j < word.size(); j++) {
			if (doc[i + j] != word[j]) {
				isSame = false;
				break;
			}
		}

		// 같다면 다음 인덱스부터 시작
		if (isSame) {
			ans++;
			i += word.size() - 1;
		}
	}

	// 정답 출력
	cout << ans;

	return 0;
}