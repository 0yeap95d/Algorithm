#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define MAX_SIZE 101
using namespace std;

int N, K;
int board[MAX_SIZE][10];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	// ���� N, ���� ���� K
	cin >> N >> K;

	// ���� �Է�
	string inp;
	for (int i = 0; i < N; i++) {
		cin >> inp;
		for (int j = 0; j < 10; j++) {
			board[i][j] = inp[j] - '0';
		}
	}

	
	while (1) {
		// ��� ����
		vector<vector<bool>> visited(N, vector<bool>(10, false));
		bool isDel = false;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 10; j++) {
				if (board[i][j] == 0 || visited[i][j]) continue;

				queue<pair<int, int>> que;
				vector<pair<int, int>> temp;

				que.push({ i, j });
				visited[i][j] = true;
				temp.push_back({ i, j });

				while (!que.empty()) {
					int x = que.front().first;
					int y = que.front().second;
					que.pop();

					for (int di = 0; di < 4; di++) {
						int nx = x + dx[di];
						int ny = y + dy[di];

						// ���� üũ
						if (nx < 0 || nx >= N || ny < 0 || ny >= 10 || visited[nx][ny]) continue;

						// ���� �� üũ
						if (board[nx][ny] != board[x][y]) continue;

						que.push({ nx, ny });
						visited[nx][ny] = true;
						temp.push_back({ nx, ny });
					}
				}

				if (temp.size() < K) continue;

				// ��� ����
				isDel = true;
				for (int i = 0; i < temp.size(); i++) {
					int x = temp[i].first;
					int y = temp[i].second;
					board[x][y] = 0;
				}
			}
		}
		
		// �� �̻� �����Ұ� ���ٸ� ����
		if (!isDel) break;

		// ��� ������
		for (int i = N - 2; i >= 0; i--) {
			for (int j = 0; j < 10; j++) {
				if (board[i][j] == 0) continue;
				int nx = i;
				while (nx + 1 < N && board[nx + 1][j] == 0) nx += 1;
				if (nx == i) continue;
				board[nx][j] = board[i][j];
				board[i][j] = 0;
			}
		}
	}

	


	// ���� ���
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 10; j++) {
			cout << board[i][j];
		}
		cout << "\n";
	}

	return 0;
}