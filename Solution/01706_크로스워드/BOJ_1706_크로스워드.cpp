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

	// ���� ũ�� R x C �Է�
	cin >> R >> C;

	// ���� �Է�
	for (int i = 0; i < R; i++) cin >> puzzle[i];

	// �ܾ� ã��
	vector<string> wordList;
	
	// ���� �ܾ� ã��
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

	//���� �ܾ� ã��
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


	// ����
	sort(wordList.begin(), wordList.end());

	// ���
	cout << wordList[0];

	return 0;
}