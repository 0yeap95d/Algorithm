#include <iostream>
#include <algorithm>
#define MAX_SIZE 4
using namespace std;

int ans;
pair<int, int> area[MAX_SIZE][MAX_SIZE];

int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };

// 물고기 이동
void moveFish(pair<int, int> data[][MAX_SIZE]) {
	for (int n = 1; n <= MAX_SIZE * MAX_SIZE; n++) {
		bool isFind = false;
		for (int i = 0; i < MAX_SIZE; i++) {
			for (int j = 0; j < MAX_SIZE; j++) {
				if (n != data[i][j].first) continue;
			
				isFind = true;
				for (int di = 0; di < 8; di++) {
					int idx = (data[i][j].second + di) % 8;
					int nx = i + dx[idx];
					int ny = j + dy[idx];

					// 경계 체크
					if (nx < 0 || nx >= MAX_SIZE || ny < 0 || ny >= MAX_SIZE) continue;

					// 상어일 때
					if (data[nx][ny].first == -1) continue;

					// 빈 공간일 때
					else if (data[nx][ny].first == 0) {
						data[nx][ny] = { data[i][j].first, idx };
						data[i][j] = { 0, 0 };
						break;
					}

					// 다른 물고기가 있을 때
					else {
						pair<int, int> temp = data[nx][ny];
						data[nx][ny] = { data[i][j].first, idx };
						data[i][j] = temp;
						break;
					}
				}
				break;
			}
			if (isFind)break;
		}
	}
}

void moveShark(int x, int y, int sum, pair<int, int> data[][MAX_SIZE]) {

	pair<int, int> arr[MAX_SIZE][MAX_SIZE];
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			arr[i][j] = data[i][j];
		}
	}

	// 상어 이동 전 물고기 이동
	moveFish(arr);

	// 상어 이동
	bool isMove = false;
	int dir = arr[x][y].second;
	for (int i = 1; i < MAX_SIZE; i++) {
		int nx = x + dx[dir] * i;
		int ny = y + dy[dir] * i;

		// 경계 체크
		if (nx < 0 || nx >= MAX_SIZE || ny < 0 || ny >= MAX_SIZE) continue;

		// 물고기가 없는 칸
		if (arr[nx][ny].first <= 0) continue;

		int num = arr[nx][ny].first;
		arr[nx][ny].first = -1;
		arr[x][y].first = 0;
		moveShark(nx, ny, sum + num, arr);
		arr[x][y].first = -1;
		arr[nx][ny].first = num;
	}

	// 상어가 더 이상 움직일 수 없을 때
	if (!isMove) {
		ans = max(ans, sum);
		return;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// 물고기 입력
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			cin >> area[i][j].first >> area[i][j].second;
			area[i][j].second--;
		}
	}

	// 상어 투입
	int sum = area[0][0].first;
	area[0][0].first = -1;

	// 상어 이동
	moveShark(0, 0, sum, area);

	// 정답 출력
	cout << ans;

	return 0;
}