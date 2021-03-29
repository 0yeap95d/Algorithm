#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#define SIZE 104
#define INF 987654321
using namespace std;

struct Prisoner {
	int door;
	int x;
	int y;
};

bool operator<(Prisoner p1, Prisoner p2) {
	return p1.door > p2.door;
}

int testcase;
int H, W;
long long Ans;
char Prison[SIZE][SIZE];
int Move[3][SIZE][SIZE];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

// BFS 
void Escape(int n, Prisoner p) {
	priority_queue<Prisoner> que;
	bool visited[SIZE][SIZE] = { false, };
	
	que.push(p);
	visited[p.x][p.y] = true;

	while (!que.empty()) {
		int x = que.top().x;
		int y = que.top().y;
		int door = que.top().door;
		Move[n][x][y] = door;
		que.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx > H + 1|| ny < 0 || ny > W + 1) continue;
			if (Prison[nx][ny] == '*' || visited[nx][ny]) continue;
			if (Prison[nx][ny] == '#') que.push({ door + 1, nx, ny });
			else que.push({ door, nx, ny });
			visited[nx][ny] = true;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> testcase;

	while (testcase--) {

		Ans = INF;
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				Move[0][i][j] = Move[1][i][j] = Move[1][i][j] = INF;
			}
		}
		memset(Prison, 0, sizeof(Prison));

		// 죄수의 상근이 위치 저장
		vector<Prisoner> prisoners;
		prisoners.push_back({ 0, 0, 0 });
		cin >> H >> W;
		for (int i = 1; i <= H; i++) {
			for (int j = 1; j <= W; j++) {
				cin >> Prison[i][j];
				if (Prison[i][j] == '$') prisoners.push_back({ 0, i, j });
			}
		}

		// BFS탐색을 통해 각 위치에 가기위해 필요한 문의 개수 기록
		for (int i = 0; i < 3; i++) Escape(i, prisoners[i]);
		
		// 각 칸에서 3명이 만났을 최소가 되는 경우 (문이 있는 칸은 세명 모두 열기때문에 -2를 해줘야함)
		for (int i = 0; i <= H + 1; i++) {
			for (int j = 0; j <= W + 1; j++) {
				long long sum = Move[0][i][j] + Move[1][i][j] + Move[2][i][j];
				if (Prison[i][j] == '#') sum = sum - 2;
				Ans = min(Ans, sum);
			}
		}

		cout << Ans << "\n";
	}

	return 0;
}

