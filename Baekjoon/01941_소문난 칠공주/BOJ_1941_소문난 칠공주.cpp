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


// 번호를 좌표로 변환
pair<int, int> numToPos(int num) {
	return { num / 5, num % 5 };
}

// 7명 중 4명 이상이 다솜파인지 체크
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

// 7명이 모두 연결되어 있는지 체크
bool isConnect(vector<int> list) {

	bool selected[5][5] = { false, };
	pair<int, int> pos;

	// 선택된 학생들 마킹
	for (int num : list) {
		pos = numToPos(num);
		selected[pos.first][pos.second] = true;
	}


	// BFS이용해서 selected에 체크된 학생들이 연결되어있는지 확인
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

			// 범위 체크
			if (nx < 0 || nx >= SIZE || ny < 0 || ny >= SIZE) continue;

			// 방문 체크
			if (!selected[nx][ny]) continue;

			que.push({ nx, ny });
			selected[nx][ny] = false;
		}
	}

	if (cnt == 7) return true;
	else return false;
}

// 전체 학생 중 7명을 뽑음
void selectStu(int cnt, int num, vector<int> list) {
	
	// 7명이 선택되었을 때
	if (cnt == 7) {
		if (moreDasom(list) && isConnect(list)) ans++;
		return;
	}

	// 7명이 선택되지 않았을 때
	if (num >= 25) return;

	selectStu(cnt, num + 1, list);
	list.push_back(num);
	selectStu(cnt + 1, num + 1, list);
}

int main() {

	// 여학생반 자리 입력
	string inp;
	for (int i = 0; i < SIZE; i++) cin >> grid[i];

	// 칠공주 결성
	selectStu(0, 0, vector<int>());

	// 정답 출력
	cout << ans;

	return 0;
}