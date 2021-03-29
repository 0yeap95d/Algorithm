#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

struct Pos {
	int x;
	int y;
	int dis;
	Pos() {}
	Pos(int x, int y, int d) : x(x), y(y), dis(d) {}
};

const int dx[4] = { -1, 0, 0, 1 };
const int dy[4] = { 0, -1, 1, 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	// �Ʊ��� ����
	int sharkSize = 2;
	int sizeUp = 0;
	Pos sharkPos;
	int map[21][21] = { 0, };
	
	// 1. �Է�
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) sharkPos = Pos(i, j, 0);
		}
	}

	int ans = 0;
	while (1) {
		// 2. ���� �� �ִ� �ִܰŸ� ����� ����Ʈ ���ϱ�
		int minDis = INF;
		bool visit[21][21] = { false, };
		vector<Pos> fish;
		queue<Pos> que;

		que.push(sharkPos);
		visit[sharkPos.x][sharkPos.y] = true;
		map[sharkPos.x][sharkPos.y] = 0;

		while (!que.empty()) {
			Pos pos = que.front();
			que.pop();

			if (minDis != INF && minDis <= pos.dis) continue;

			for (int k = 0; k < 4; k++) {
				int nx = pos.x + dx[k];
				int ny = pos.y + dy[k];

				// �����ʰ�, �湮üũ
				if (nx < 0 || nx >= n ||
					ny < 0 || ny >= n ||
					visit[nx][ny]) continue;

				// ���� �� �ִ� ������϶�
				if (map[nx][ny] != 0 && map[nx][ny] < sharkSize) {
					minDis = pos.dis + 1;
					visit[nx][ny] = true;
					fish.push_back(Pos(nx, ny, minDis));
					continue;
				}

				// �������⸸ ������ ��
				if (map[nx][ny] == sharkSize || map[nx][ny] == 0) {
					que.push(Pos(nx, ny, pos.dis + 1));
					visit[nx][ny] = true;
				}
			}
		}

		// 3-1. ����Ʈ�� ��������� ����
		if (fish.empty()) break;

		// 3-2. ����Ʈ �� ���� ��, ���ʿ� �ִ� ����� ĭ���� �̵�
		Pos point(n, n, 0);
		for (Pos p : fish) {
			if (point.x == p.x) {
				if (point.y > p.y) point = p;
			}
			else if (point.x > p.x) point = p; 
		}

		sharkPos = point;
		ans += sharkPos.dis;
		sharkPos.dis = 0;
		sizeUp++;
		if (sizeUp == sharkSize) {
			sizeUp = 0;
			sharkSize++;
		}
	}

	cout << ans;

	return 0;
}