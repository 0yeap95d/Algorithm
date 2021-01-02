#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// 참외의 개수 N
	int N;
	cin >> N;

	// 참외밭 정보 입력, 너비 높이 최대값 저장
	vector<pair<int, int>> field;
	field.assign(6, {0, 0});
	int maxWidth, maxHeight, ans;
	for (int i = 0; i < 6; i++) {
		cin >> field[i].first >> field[i].second;
		if (field[i].first < 3) maxWidth = max(maxWidth, field[i].second);
		else maxHeight = max(maxHeight, field[i].second);
	}

	// 정사각형 넓이
	ans = maxWidth * maxHeight;

	// 들어간 부분의 넓이 구해서 전체 넓이에서 빼기
	for (int i = 0; i < 6; i++) {
		int a = i % 6;
		int b = (i + 1) % 6;
		int c = (i + 2) % 6;
		int d = (i + 3) % 6;
		if (field[a].first == field[c].first && field[b].first == field[d].first) {
			ans -= field[b].second * field[c].second;
			break;
		}
	}

	// 정답 출력
	ans *= N;
	cout << ans;

	return 0;
}