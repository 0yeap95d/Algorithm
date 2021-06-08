#include <iostream>
#include <vector>
#define MAX 30
#define SIZE 500
using namespace std;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int satisfy[5] = { 0, 1, 10, 100, 1000 };

int N;
int seat[MAX][MAX];
vector<int> order;
int friends[SIZE][4];

void Init() {
	cin >> N;
	order.resize(N * N);
	for (int i = 0; i < N * N; i++) {
		cin >> order[i];
		for (int j = 0; j < 4; j++) cin >> friends[order[i]][j];
	}
}

bool isNotIn(int x, int y) {
	return x < 0 || x >= N || y < 0 || y >= N;
}

pair<int, int> getCountFriends(int x, int y, int num) {
	int res = 0;
	int cntEmpty = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (isNotIn(nx, ny)) continue;
		if (seat[nx][ny] == 0) {
			cntEmpty++;
			continue;
		}
		for (int j = 0; j < 4; j++) 
			if (friends[num][j] == seat[nx][ny]) res++;
	}
	return make_pair(res, cntEmpty);
}

void setStu(int num) {
	int maxFriends = -1;
	int emptySeat = -1;
	pair<int, int> pos(-1, -1);
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			if (seat[x][y] != 0) continue;
			pair<int, int> info = getCountFriends(x, y, num);
			int cntFriend = info.first;
			int cntEmpty = info.second;
			if (maxFriends < cntFriend || (maxFriends == cntFriend && emptySeat < cntEmpty)) {
				pos = { x, y };
				maxFriends = cntFriend;
				emptySeat = cntEmpty;
			}
		}
	}
	seat[pos.first][pos.second] = num;
}

int getSatisfaction() {
	int res = 0;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			int cntFriend = getCountFriends(x, y, seat[x][y]).first;
			res += satisfy[cntFriend];
		}
	}
	return res;
}

void Solve() {
	for (int num : order) setStu(num);
	int answer = getSatisfaction();
	cout << answer;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	Init();
	Solve();

 	return 0;
}