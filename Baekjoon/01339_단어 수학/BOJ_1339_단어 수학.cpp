#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int N, Ans;
int Alphabet[26];
int Table[26];

// 가중치가 큰 알파벳부터 높은 숫자 배치
void setTable() {
	int val, idx, num = 9;
	while (num >= 0) {
		val = idx = 0;
		for (int i = 0; i < 26; i++) {
			if (val < Alphabet[i]) {
				val = Alphabet[i];
				idx = i;
			}
		}
		if (val == 0) break;
		Table[idx] = num--;
		Alphabet[idx] = 0;
	}
}

// 문자열을 정수로 변환
int StringToInt(string word) {
	int result = 0;
	for (int i = 0; i < word.size(); i++) {
		result = result * 10;
		result += Table[word[i] - 'A'];
	}
	return result;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N;
	vector<string> words;
	for (int i = 0; i < N; i++) {
		string inp;
		cin >> inp;
		words.push_back(inp);

		// 각 알파벳의 자리수에 따라 가중치 설정
		int temp = 1;
		for (int j = inp.size() - 1; j >= 0; j--) {
			Alphabet[inp[j] - 'A'] += temp;
			temp = temp * 10;
		}
	}

	// 문자열을 정수로 바꾸기위한 테이블 셋팅
	setTable();

	for (string word : words) Ans = Ans + StringToInt(word);

	// 정답 출력
	cout << Ans;

	return 0;
}