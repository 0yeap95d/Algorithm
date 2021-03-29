#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int N, K, Ans;
string Board[2];
queue<pair<int, pair<int, int>>> Pos;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> K;
	cin >> Board[0] >> Board[1];

	Pos.push({ 0, { 0, 0 } });
	while (!Pos.empty()) {
		int time = Pos.front().first;
		int x = Pos.front().second.first;
		int y = Pos.front().second.second;
		Pos.pop();

		// 탈출 조건
		if (y + 1 >= N || y + K >= N) {
			Ans = 1;
			break;
		}

		// 이동
		if (Board[x][y + 1] != '0') {
			Board[x][y + 1] = '0';
			Pos.push({ time + 1, { x, y + 1 } });
		}
		if (y - 1 > time&& Board[x][y - 1] != '0') {
			Board[x][y - 1] = '0';
			Pos.push({ time + 1, { x, y - 1 } });
		}
		if (x == 0 && Board[1][y + K] != '0') {
			Board[1][y + K] = '0';
			Pos.push({ time + 1, { 1, y + K } });
		}
		else if (x == 1 && Board[0][y + K] != '0') {
			Board[0][y + K] = '0';
			Pos.push({ time + 1, { 0, y + K } });
		}

		time++;
	}

	cout << Ans;

	return 0;
}