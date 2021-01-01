#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define SIZE 6
using namespace std;

int N, ans;
map<int, int> cross;
vector<vector<int>> inp;

// 주사위 높이, 쌓을 면, 옆면 합
void stackDice(int depth, int delVal, int sum) {
	if (depth >= N) {
		ans = max(ans, sum);
		return;
	}

	vector<int> dice(inp[depth].begin(), inp[depth].end());

	// 쌓을 아래 위 삭제
	for (int i = 0; i < SIZE; i++) {
		if (delVal == dice[i]) {
			delVal = dice[cross[i]];
			dice[i] = dice[cross[i]] = 0;
			break;
		}
	}

	// 옆면중 가장 큰 값 고르기
	int val = 0;
	for (int i = 0; i < SIZE; i++) val = max(val, dice[i]);
	
	// 다음 주사위로 이동
	stackDice(depth + 1, delVal, sum + val);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	inp.assign(N, vector<int>(SIZE, 0));

	// 주사위 마주보는 면 맵핑
	cross[0] = 5;
	cross[1] = 3;
	cross[2] = 4;
	cross[3] = 1;
	cross[4] = 2;
	cross[5] = 0;

	// 주사위 입력받기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < SIZE; j++) cin >> inp[i][j];
	}

	// 주사위 쌓기
	for (int i = 1; i <= SIZE; i++) stackDice(0, i, 0);

	// 정답 출력
	cout << ans;

	return 0;
}