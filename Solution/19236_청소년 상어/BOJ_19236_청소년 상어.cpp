#include <iostream>
#include <algorithm>
#define MAX_SIZE 4
using namespace std;

int ans;
pair<int, int> area[MAX_SIZE][MAX_SIZE];

int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };

// ����� �̵�
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

					// ��� üũ
					if (nx < 0 || nx >= MAX_SIZE || ny < 0 || ny >= MAX_SIZE) continue;

					// ����� ��
					if (data[nx][ny].first == -1) continue;

					// �� ������ ��
					else if (data[nx][ny].first == 0) {
						data[nx][ny] = { data[i][j].first, idx };
						data[i][j] = { 0, 0 };
						break;
					}

					// �ٸ� ����Ⱑ ���� ��
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

	// ��� �̵� �� ����� �̵�
	moveFish(arr);

	// ��� �̵�
	bool isMove = false;
	int dir = arr[x][y].second;
	for (int i = 1; i < MAX_SIZE; i++) {
		int nx = x + dx[dir] * i;
		int ny = y + dy[dir] * i;

		// ��� üũ
		if (nx < 0 || nx >= MAX_SIZE || ny < 0 || ny >= MAX_SIZE) continue;

		// ����Ⱑ ���� ĭ
		if (arr[nx][ny].first <= 0) continue;

		int num = arr[nx][ny].first;
		arr[nx][ny].first = -1;
		arr[x][y].first = 0;
		moveShark(nx, ny, sum + num, arr);
		arr[x][y].first = -1;
		arr[nx][ny].first = num;
	}

	// �� �� �̻� ������ �� ���� ��
	if (!isMove) {
		ans = max(ans, sum);
		return;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// ����� �Է�
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			cin >> area[i][j].first >> area[i][j].second;
			area[i][j].second--;
		}
	}

	// ��� ����
	int sum = area[0][0].first;
	area[0][0].first = -1;

	// ��� �̵�
	moveShark(0, 0, sum, area);

	// ���� ���
	cout << ans;

	return 0;
}