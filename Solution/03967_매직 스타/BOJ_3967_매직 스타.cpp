#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

string inp[5];
vector<int> arr;
bool visited[13];
int check[6][4] = {
	{1, 3, 6, 8},
	{8, 9, 10, 11},
	{1, 4, 7, 11},
	{2, 3, 4, 5},
	{2, 6, 9, 12},
	{5, 7, 10, 12}
};
pair<int, int> pos[13] = {
	{0, 0}, {0, 4},
	{1, 1}, {1, 3}, {1, 5}, {1, 7},
	{2, 2}, {2, 6},
	{3, 1}, {3, 3}, {3, 5}, {3, 7},
	{4, 4}
};

bool isCorrect() {
	for (int i = 0; i < 6; i++) {
		int sum = 0;
		for (int j = 0; j < 4; j++) sum = sum + arr[check[i][j]];
		if (sum != 26) return false;
	}
	return true;
}

bool setNum() {
	// ºóÄ­ Ã£±â
	int idx = -1;
	for (int i = 1; i < arr.size(); i++) {
		if (arr[i] == 0) {
			idx = i;
			break;
		}
	}

	// ºóÄ­ÀÌ ´õ ÀÌ»ó ¾øÀ» ¶§
	if (idx == -1) {
		if (isCorrect()) {
			for (int i = 1; i <= 12; i++) inp[pos[i].first][pos[i].second] = (char)(arr[i] + 'A' - 1);
			for (int i = 0; i < 5; i++) cout << inp[i] << "\n";
			return true;
		}
		else return false;
	}

	// ºóÄ­ÀÌ Á¸ÀçÇÒ ¶§
	else {
		for (int i = 1; i <= 12; i++) {
			if (visited[i]) continue;
			arr[idx] = i;
			visited[i] = true;
			if (setNum()) return true;
			visited[i] = false;
			arr[idx] = 0;
		}
	}

	return false;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	arr.push_back(0);
	for (int i = 0; i < 5; i++) {
		cin >> inp[i];
		for (char ch : inp[i]) {
			if (ch == '.') continue;
			else if (ch == 'x') arr.push_back(0);
			else {
				arr.push_back(ch - 'A' + 1);
				visited[ch - 'A' + 1] = true;
			}
		}
	}

	setNum();

	return 0;
}