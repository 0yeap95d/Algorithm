#include <iostream>
#include <queue>
#define SIZE 51
#define INF 987654321
using namespace std;

struct Data {
	int x;
	int y;
	int garbage;
	int side;

	bool operator>(Data data) {
		if (this->garbage == data.garbage) return this->side > data.side;
		return this->garbage > data.garbage;
	}
};

int N, M;
char Forest[SIZE][SIZE];
Data Position[SIZE][SIZE];
queue<Data> que;
pair<int, int> End;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

// 쓰레기가 옆에 있는지 확인
bool sideGarbage(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
		if (Forest[nx][ny] == 'g') return true;
	}

	return false;
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> Forest[i];
		for (int j = 0; j < M; j++) {
			Position[i][j].x = i;
			Position[i][j].y = j;
			Position[i][j].garbage = Position[i][j].side = INF;
			if (Forest[i][j] == 'S') {
				Position[i][j].garbage = Position[i][j].side = 0;
				que.push(Position[i][j]);
			}
			if (Forest[i][j] == 'F') End = { i, j };
		}
	}

	Data Ans;
	while (!que.empty()) {
		Data data = que.front();
		que.pop();

		for (int i = 0; i < 4; i++) {
			int nx = data.x + dx[i];
			int ny = data.y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

			Data temp = data;
			temp.x = nx, temp.y = ny;

			if (Forest[nx][ny] == 'g') temp.garbage++;
			else if (Forest[nx][ny] == '.' && sideGarbage(nx, ny)) temp.side++;

			if (Position[nx][ny] > temp) {
				Position[nx][ny] = temp;
				if (Forest[nx][ny] != 'F') que.push(temp);
			}
		}
	}

	cout << Position[End.first][End.second].garbage << " ";
	cout << Position[End.first][End.second].side;


	return 0;
}