#include <iostream>
#define SIZE 21
using namespace std;

int N, M, x, y, K;
int Map[SIZE][SIZE];
int Dice[6];

int dx[5] = { 0, 0, 0, -1, 1 };
int dy[5] = { 0, 1, -1, 0, 0 };

int Roll_Dice(int Command) {
	int nx = x + dx[Command];
	int ny = y + dy[Command];

	if (nx < 0 || nx >= N || ny < 0 || ny >= M) return -1;
	
	if (Command == 1) {
		int temp = Dice[0];
		Dice[0] = Dice[3];
		Dice[3] = Dice[5];
		Dice[5] = Dice[2];
		Dice[2] = temp;
	}
	else if (Command == 2) {
		int temp = Dice[0];
		Dice[0] = Dice[2];
		Dice[2] = Dice[5];
		Dice[5] = Dice[3];
		Dice[3] = temp;
	}
	else if (Command == 3) {
		int temp = Dice[0];
		Dice[0] = Dice[4];
		Dice[4] = Dice[5];
		Dice[5] = Dice[1];
		Dice[1] = temp;
	}
	else {
		int temp = Dice[0];
		Dice[0] = Dice[1];
		Dice[1] = Dice[5];
		Dice[5] = Dice[4];
		Dice[4] = temp;
	}

	x = nx, y = ny;
	if (Map[x][y] == 0) Map[x][y] = Dice[5];
	else {
		Dice[5] = Map[x][y];
		Map[x][y] = 0;
	}

	return Dice[0];
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> M >> x >> y >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> Map[i][j];
		}
	}

	int ans,command;
	for (int i = 0; i < K; i++) {
		cin >> command;
		ans = Roll_Dice(command);
		if (ans != -1) cout << ans << "\n";
	}

	return 0;
}