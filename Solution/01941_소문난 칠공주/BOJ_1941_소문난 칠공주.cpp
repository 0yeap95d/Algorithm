#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define SIZE 5
using namespace std;

char grid[SIZE][SIZE];
int ans;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };


// ��ȣ�� ��ǥ�� ��ȯ
pair<int, int> numToPos(int num) {
	return { num / 5, num % 5 };
}

// 7�� �� 4�� �̻��� �ټ������� üũ
bool moreDasom(vector<int> list) {
	pair<int, int> pos;

	int cnt = 0;
	for (int num : list) {
		pos = numToPos(num);
		if (grid[pos.first][pos.second] == 'S') cnt++;
	}

	if (cnt < 4) return false;
	else return true;
}

// 7���� ��� ����Ǿ� �ִ��� üũ
bool isConnect(vector<int> list) {

	bool selected[5][5] = { false, };
	pair<int, int> pos;

	// ���õ� �л��� ��ŷ
	for (int num : list) {
		pos = numToPos(num);
		selected[pos.first][pos.second] = true;
	}


	// BFS�̿��ؼ� selected�� üũ�� �л����� ����Ǿ��ִ��� Ȯ��
	int cnt = 0;
	queue<pair<int, int>> que;

	que.push(pos);
	selected[pos.first][pos.second] = false;

	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();
		cnt++;

		for (int di = 0; di < 4; di++) {
			int nx = x + dx[di];
			int ny = y + dy[di];

			// ���� üũ
			if (nx < 0 || nx >= SIZE || ny < 0 || ny >= SIZE) continue;

			// �湮 üũ
			if (!selected[nx][ny]) continue;

			que.push({ nx, ny });
			selected[nx][ny] = false;
		}
	}

	if (cnt == 7) return true;
	else return false;
}

// ��ü �л� �� 7���� ����
void selectStu(int cnt, int num, vector<int> list) {
	
	// 7���� ���õǾ��� ��
	if (cnt == 7) {
		if (moreDasom(list) && isConnect(list)) ans++;
		return;
	}

	// 7���� ���õ��� �ʾ��� ��
	if (num >= 25) return;

	selectStu(cnt, num + 1, list);
	list.push_back(num);
	selectStu(cnt + 1, num + 1, list);
}

int main() {

	// ���л��� �ڸ� �Է�
	string inp;
	for (int i = 0; i < SIZE; i++) cin >> grid[i];

	// ĥ���� �Ἲ
	selectStu(0, 0, vector<int>());

	// ���� ���
	cout << ans;

	return 0;
}