#include <iostream>
#include <algorithm>
#define COL_SIZE 11
#define ROW_SIZE 31
#define INF 987654321
using namespace std;

int N, M, H, Ans;
int Ladder[ROW_SIZE][COL_SIZE];

// 사다리 정보 입력
void Setting_Ladder() {
	cin >> N >> M >> H;

	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		Ladder[a][b] = 1;
		Ladder[a][b + 1] = -1;
	}

	Ans = INF;
}

// 사다리가 자기 위치로 돌아오는지 확인
bool isCorrect() {
	for (int c = 1; c <= N; c++) {
		int pos = c;
		for (int r = 1; r <= H; r++) pos += Ladder[r][pos];
		if (pos != c) return false;
	}
	return true;
}

void Update_Ladder(int line, int sum) {

	// Ans 보다 더 많은 사다리를 추가할 수 없음
	if (Ans <= sum || 3 < sum) return;

	// 더 이상 추가할 사다리가 없을 때 
	if (isCorrect()) {
		Ans = min(Ans, sum);
		return;
	}

	// 오른쪽 연결 추가
	for (int i = line; i <= H; i++) {
		for (int j = 1; j < N; j++) {
			if (Ladder[i][j] != 0 || Ladder[i][j + 1] != 0) continue;
			Ladder[i][j] = 1;
			Ladder[i][j + 1] = -1;
			Update_Ladder(i, sum + 1);
			Ladder[i][j] = Ladder[i][j + 1] = 0;
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	Setting_Ladder();
	Update_Ladder(1, 0);

	if (Ans == INF) Ans = -1;
	cout << Ans;

	return 0;
}