#include <iostream>
#include <vector>
using namespace std;

int N, M, K;

int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

struct Fire {
	int x;
	int y;
	int m;
	int s;
	int d;
};

vector<Fire> map[51][51];
vector<Fire> fireList;

// 2개 이상 파이어볼 있는 칸 처리
void sumFire() {

	fireList.clear();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j].size() == 0) continue;
			else if (map[i][j].size() == 1) fireList.push_back(map[i][j][0]);
			else {
				int m, s, d, even, odd, add;
				m = s = d = even = odd = add = 0;
				for (Fire fire : map[i][j]) {
					m += fire.m;
					s += fire.s;
					if (fire.d % 2 == 0) even++;
					else odd++;
				}

				m /= 5;
				s /= map[i][j].size();
				if (even != 0 && odd != 0) add++;

				map[i][j].clear();
				if (m == 0) continue;
				for (int dir = 0; dir < 8; dir += 2) {
					fireList.push_back({ i, j, m, s, dir + add });
					map[i][j].push_back({ i, j, m, s, dir + add });
				}

			}
		}
	}
}

// 파이어볼 이동
void moveFire() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) map[i][j].clear();
	}

	for (Fire fire : fireList) {
		int nx = fire.x + dx[fire.d] * fire.s;
		int ny = fire.y + dy[fire.d] * fire.s;

		while (nx < 0) nx += N;
		while (ny < 0) ny += N;
		while (nx >= N) nx -= N;
		while (ny >= N) ny -= N;

		fire.x = nx;
		fire.y = ny;

		map[nx][ny].push_back(fire);
	}

	sumFire();
}

int getAnswer() {
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j].size() == 0) continue;
			for (Fire fire : map[i][j]) ans += fire.m;
		}
	}
	return ans;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> M >> K;

	int x, y, m, s, d;
	for (int i = 0; i < M; i++) {
		cin >> x >> y >> m >> s >> d;
		fireList.push_back({ x, y, m, s, d });
		map[x][y].push_back({ x, y, m, s, d });
	}

	for (int i = 0; i < K; i++) moveFire();
	
	cout << getAnswer();

	return 0;
}