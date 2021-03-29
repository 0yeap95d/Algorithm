#include <iostream>
#include <vector>
#include <algorithm>
#define pii pair<int, int>
using namespace std;

int dx[5] = { 0, 1, -1, 0, 0 };
int dy[5] = { 0, 0, 0, 1, -1 };

int changClock[5] = { 0, 4, 3, 1, 2 };
int changAntiClock[5] = { 0, 3, 4, 2, 1 };

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int width, height, N;
	cin >> width >> height >> N;

	// �ѷ� ����
	int length = (width * 2) + (height * 2);


	pii pos, inp;
	int dir, dis, ans = 0;
	vector<pair<int, pii>> store;
	for (int i = 0; i < N + 1; i++) {
		// 1: ��, 2: ��, 3: ��, 4: ��
		// 1, 2�ϋ� ���ʺ��� | 3,4�϶� ���ʺ��� �Ÿ�
		cin >> dir >> dis;

		// ��ǥ������ ��ȯ
		if (dir == 1) inp = pii(dis, height);
		else if (dir == 2) inp = pii(dis, 0);
		else if (dir == 3) inp = pii(0, height - dis);
		else if (dir == 4) inp = pii(width, height - dis);
		
		if (i == N) pos = inp;
		else store.push_back(make_pair(dir, inp));
	}

	for (int i = 0; i < N; i++) {
		// �ð�������� ����
		dir = store[i].first;
		pii temp = store[i].second;

		int resClock = 0;
		while (pos.first != temp.first || pos.second != temp.second) {
			int nx = temp.first + dx[dir];
			int ny = temp.second + dy[dir];
			// ������ ����� ������ȯ
			if (nx < 0 || nx > width || ny < 0 || ny > height) {
				dir = changClock[dir];
				continue;
			}
			temp.first = nx, temp.second = ny;
			resClock++;
		}
		
		// �ݽð�� ����
		int resAntiClock = length - resClock;
		
		ans += min(resClock, resAntiClock);
	}

	cout << ans;

	return 0;
}