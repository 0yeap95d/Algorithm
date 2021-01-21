#include <iostream>
#include <queue>
#define endl '\n'
using namespace std;

int N, M, T;
int board[51][51];
int temp_list[51];
int dx[4] = { 0, 0, 1, -1};
int dy[4] = { -1, 1, 0, 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> T;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}


	while (T--) {
		
		// x, d, k 입력 (x배수인 원판을 d방향으로 k 칸 회전, d = 0 : 시계, d = 1 : 반시계)
		int X, D, K;
		cin >> X >> D >> K; 
	
		// 회전
		if (D == 0) {	// 시계방향
			for (int i = 0; i < N; i++) {

				// x의 배수가 아니면 continue
				if ((i + 1) % X != 0) continue;	
				
				for (int j = 0; j < M; j++) {
					int nx = (j + K) % M;
					temp_list[nx] = board[i][j];
				}
				for (int j = 0; j < M; j++) board[i][j] = temp_list[j];
			}
		}
		else {			// 반시계방향
			for (int i = 0; i < N; i++) {

				// x의 배수가 아니면 continue
				if ((i + 1) % X != 0) continue;

				for (int j = 0; j < M; j++) {
					int nx = (j + K) % M;
					temp_list[j] = board[i][nx];
				}
				for (int j = 0; j < M; j++) board[i][j] = temp_list[j];
			}
		}


		// 인접하면서 같은 수 삭제
		bool isExis = false;
		queue<pair<int, int>> que;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (board[i][j] == 0) continue;
				
				bool isSame = false;
				int x, y, value;

				que.push(make_pair(i, j));
				value = board[i][j];
				board[i][j] = 0;

				while (!que.empty()) {
					x = que.front().first;
					y = que.front().second;
					que.pop();

					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];
						if (nx < 0 || nx >= N) continue;
						if (ny < 0) ny += M;
						if (ny >= M) ny -= M;
						if (board[nx][ny] != value) continue;
						que.push(make_pair(nx, ny));
						board[nx][ny] = 0;
						isExis = true;
						isSame = true;
					}
				}
				if (!isSame) board[i][j] = value;
			}
		}

		// 같은 수 하나라도 있을 때
		if (isExis) continue;

		// 같은 수 없을때
		// 평균 구하기
		double cnt = 0;
		double sum = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (board[i][j] == 0) continue;
				sum += board[i][j];
				cnt++;
			}
		}

		double avg = sum / cnt;
		
		// 평균보다 큰 수 -1, 평균보다 작은 수 +1

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (board[i][j] == 0) continue;
				if (board[i][j] < avg) board[i][j]++;
				else if (board[i][j] > avg) board[i][j]--;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			ans += board[i][j];
		}
	}

	cout << ans;

	return 0;
}