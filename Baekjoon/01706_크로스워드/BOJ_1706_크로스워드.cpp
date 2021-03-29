#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int R, C;
char puzzle[21][21];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// 퍼즐 크기 R x C 입력
	cin >> R >> C;

	// 퍼즐 입력
	for (int i = 0; i < R; i++) cin >> puzzle[i];

	// 단어 찾기
	vector<string> wordList;
	
	// 가로 단어 찾기
	for (int i = 0; i < R; i++) {
		string word;
		for (int j = 0; j < C; j++) {
			if (puzzle[i][j] == '#') {
				if (word.size() > 1) wordList.push_back(word);
				word = "";
				continue;
			}
			word += puzzle[i][j];
		}
		if (word.size() > 1) wordList.push_back(word);
	}

	//세로 단어 찾기
	for (int j = 0; j < C; j++) {
		string word;
		for (int i = 0; i < R; i++) {
			if (puzzle[i][j] == '#') {
				if (word.size() > 1) wordList.push_back(word);
				word = "";
				continue;
			}
			word += puzzle[i][j];
		}
		if (word.size() > 1) wordList.push_back(word);
	}


	// 정렬
	sort(wordList.begin(), wordList.end());

	// 출력
	cout << wordList[0];

	return 0;
}