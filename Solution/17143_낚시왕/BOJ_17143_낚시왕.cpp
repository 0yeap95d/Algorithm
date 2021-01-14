#include <iostream>
#include <queue>
#define SIZE 101
using namespace std;

struct Shark {
	int r;	
	int c;
	int s;
	int d;
	int z;
};

int R, C, M, ans;
Shark map[SIZE][SIZE];

Shark nextPos(Shark shark) {
	int move;

	// 위, 아래 이동
	if (shark.d < 3) {
		if (shark.d == 1) move = (R - 1) + ((R - 1) - shark.r);
		else move = shark.r;
		move += shark.s;

		if ((move / (R - 1)) % 2 == 0) shark.d = 2;
		else shark.d = 1;

		if (shark.d == 2) shark.r = move % (R - 1);
		else shark.r = (R - 1) - move % (R - 1);
	}
	
	// 좌, 우 이동
	else {
		if (shark.d == 4) move = (C - 1) + ((C - 1) - shark.c);
		else move = shark.c;
		move += shark.s;

		if ((move / (C - 1)) % 2 == 0) shark.d = 3;
		else shark.d = 4;

		if (shark.d == 3) shark.c = move % (C - 1);
		else shark.c = (C - 1) - move % (C - 1);
	}

	return shark;
}

void moveShark() {

	queue<Shark> que;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j].z == 0) continue;
			que.push(nextPos(map[i][j]));
			map[i][j] = { 0, 0, 0, 0, 0 };
		}
	}

	while (!que.empty()) {
		Shark shark = que.front();
		que.pop();

		if (map[shark.r][shark.c].z > shark.z) continue;
		map[shark.r][shark.c] = shark;
	}
}

void catchShark(int pos) {
	for (int i = 0; i < R; i++) {
		if (map[i][pos].z == 0) continue;
		ans += map[i][pos].z;
		map[i][pos] = { 0, 0, 0, 0, 0 };
		return;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> R >> C >> M;

	int r, c, s, d, z;
	for (int i = 0; i < M; i++) {
		cin >> r >> c >> s >> d >> z;
		map[r - 1][c - 1] = { r - 1, c - 1, s, d, z };
	}

	for (int i = 0; i < C; i++) {
		catchShark(i);
		moveShark();
	}

	cout << ans;

	return 0;
}