#include <iostream>
#include <vector>
#include <string.h>
#define SIZE 102
#define pii pair<int, int>
using namespace std;

int paper[SIZE][SIZE];
vector<int> ans;

// 색종이 붙이기
void setPaper(int num, int x, int y, int width, int height) {
	int cnt = 0;
	for (int i = x; i < x + width; i++) {
		for (int j = y; j < y + height; j++) {
			// 이미 다른 색종이가 붙어있을때
			if (paper[i][j] != -1) ans[paper[i][j]]--;
			paper[i][j] = num;
			cnt++;
		}
	}
	ans.push_back(cnt);
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(paper, -1, sizeof(paper));

	int N;
	cin >> N;

	int x, y, width, height;
	for (int i = 0; i < N; i++) {
		cin >> x >> y >> width >> height;
		setPaper(i, x, y, width, height);
	}

	for (int i : ans) cout << i << endl;

	return 0;
}