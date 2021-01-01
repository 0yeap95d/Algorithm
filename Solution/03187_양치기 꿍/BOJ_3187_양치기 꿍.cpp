#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
����
1. ���� ��Ÿ�� ���� �ȿ��� ���� ���뺸�� ������ ���밡 ���� ��Ƹ��� (�� > ����)
2. �� ���� ��� ���� ���� ��Ƹ��� (�� <= ����)
*/

int R, C;
vector<vector<char>> map;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	// �Է� | �� ���� '.', ��Ÿ�� '#', ���� 'v', �� 'k'
	cin >> R >> C;
	map.assign(R, vector<char>(C, 0));
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			cin >> map[r][c];
		}
	}

	int ans[2] = { 0, };
	int sheep, wolf;
	queue<pair<int, int>> que;
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			
			// ��Ÿ���� ��
			if (map[r][c] == '#') continue;

			// ��Ÿ�� �ƴ� ��, ���� �ȿ� �˻�
			que.push({ r, c });
			sheep = wolf = 0;

			if (map[r][c] == 'v') wolf++;
			else if (map[r][c] == 'k') sheep++;
			map[r][c] = '#';

			while (!que.empty()) {
				int x = que.front().first;
				int y = que.front().second;
				que.pop();

				// ����� Ž��
				for (int i = 0; i < 4; i++) {
					int nx = x + dx[i];
					int ny = y + dy[i]; 
					if (nx < 0 || nx >= R || ny < 0 || ny >= C || map[nx][ny] == '#') continue;
					que.push({ nx, ny });
					if (map[nx][ny] == 'v') wolf++;
					else if (map[nx][ny] == 'k') sheep++;
					map[nx][ny] = '#';
				}
			}

			if (sheep > wolf) wolf = 0;
			else sheep = 0;

			ans[0] += sheep;
			ans[1] += wolf;
		}
	}

	cout << ans[0] << " " << ans[1];


	return 0;
}