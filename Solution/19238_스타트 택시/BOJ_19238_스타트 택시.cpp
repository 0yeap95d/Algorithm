#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
#define SIZE 21
using namespace std;

int N, M, Fuel;
int Map[SIZE][SIZE];
pair<int, int> Taxi;
vector<pair<int, int>> Cust, Dest;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

// 승객 고르기
int PickUp() {

	queue<pair<pair<int, int>, int>> que;
	bool visited[SIZE][SIZE] = { false, };

	que.push({ Taxi, 0 });
	visited[Taxi.first][Taxi.second] = true;

	int Dist = INF;
	int CustNum = -1;

	while (!que.empty()) {
		int x = que.front().first.first;
		int y = que.front().first.second;
		int t = que.front().second;
		que.pop();

		// 연료량으로 갈 수 없거나, 최소거리보다 멀리 있을 때 
		if (Fuel < t || Dist < t) continue;

		// 같은 거리라면 행 번호가 작은 순서, 행 번호도 같다면 열 변호가 작은 순서
		if (Map[x][y] >= 2) {
			if (CustNum == -1) {
				Dist = t;
				CustNum = Map[x][y] - 2;
				continue;
			}
			else if (Cust[CustNum].first > x) {
				Dist = t;
				CustNum = Map[x][y] - 2;
				continue;
			}
			else if (Cust[CustNum].first == x && Cust[CustNum].second > y) {
				Dist = t;
				CustNum = Map[x][y] - 2;
				continue;
			}
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (visited[nx][ny] || Map[nx][ny] == 1 || Dist <= t) continue;

			que.push({ { nx, ny }, t + 1 });
			visited[nx][ny] = true;
		}
	}

	if (CustNum != -1) {
		pair<int, int> cust = Cust[CustNum];
		Map[cust.first][cust.second] = 0;
		Fuel = Fuel - Dist;
	}

	return CustNum;
}

// 목적지 이동
int Move_Taxi(int Num) {
	pair<int, int> dest = Dest[Num];
	queue<pair<pair<int, int>, int>> que;
	bool visited[SIZE][SIZE] = { false, };

	que.push({ Cust[Num], 0 });
	visited[Cust[Num].first][Cust[Num].second] = true;

	while (!que.empty()) {
		int x = que.front().first.first;
		int y = que.front().first.second;
		int t = que.front().second;
		que.pop();

		// 연료가 다 떨어졌을 때
		if (Fuel <= t) break;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (Map[nx][ny] == 1 || visited[nx][ny]) continue;

			if (dest == make_pair(nx, ny)) {
				Taxi = dest;
				return t + 1;
			}

			que.push({ {nx, ny}, t + 1 });
			visited[nx][ny] = true;
		}
	}
	return -1;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> M >> Fuel;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Map[i][j];
		}
	}
	cin >> Taxi.first >> Taxi.second;
	Taxi.first--, Taxi.second--;

	Cust.resize(M);
	Dest.resize(M);
	for (int i = 0; i < M; i++) {
		cin >> Cust[i].first >> Cust[i].second;
		cin >> Dest[i].first >> Dest[i].second;

		Cust[i].first--, Cust[i].second--;
		Dest[i].first--, Dest[i].second--;

		Map[Cust[i].first][Cust[i].second] = i + 2;
	}

	while (M--) {
		int CustNum = PickUp();
		if (CustNum < 0) {
			Fuel = -1;
			break;
		}

		int Dist = Move_Taxi(CustNum);
		if (Dist >= 0) Fuel = Fuel + Dist;
		else {
			Fuel = -1;
			break;
		}
	}

	cout << Fuel;

	return 0;
}