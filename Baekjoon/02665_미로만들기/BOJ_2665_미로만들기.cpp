#include <iostream>
#include <queue>
#define MAX 51
#define INF 987654321
using namespace std;

struct Position {
	int x;
	int y;
	int cnt;
};

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int N;
bool board[MAX][MAX];
int visited[MAX][MAX];

void init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string inp;
		cin >> inp;
		for (int j = 0; j < N; j++) {
			if (inp[j] == '1') board[i][j] = true;
			visited[i][j] = INF;
		}
	}
}

void BFS() {
	queue<Position> que;
	int cnt = board[0][0] ? 0 : 1;
	que.push({ 0, 0, cnt });
	visited[0][0] = cnt;

	while (!que.empty()) {
		int x = que.front().x;
		int y = que.front().y;
		int cnt = que.front().cnt;
		que.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

			int ncnt = board[nx][ny] ? cnt : cnt + 1;
			if (visited[nx][ny] <= ncnt) continue;

			que.push({ nx, ny, ncnt });
			visited[nx][ny] = ncnt;
		}
	}
}

void print() {
	cout << visited[N - 1][N - 1];
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	init();
	BFS();
	print();

	return 0;
}