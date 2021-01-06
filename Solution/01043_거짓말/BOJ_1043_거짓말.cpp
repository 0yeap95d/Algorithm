#include <iostream>
#include <vector>
#define MAX_SIZE 51
using namespace std;

int N, M, trueNum;
int root[MAX_SIZE];
int height[MAX_SIZE];

vector<bool> person;
vector<int> truePerson;
vector<vector<int>> party;

void makeSet() {
	for (int i = 1; i <= N; i++) {
		root[i] = i;
		height[i] = 0;
	}
}

int Find(int x) {
	if (root[x] == x) return x;
	return root[x] = Find(root[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	// �� ���� root�� ������ �̹� ���� Ʈ��
	if (x == y) return;

	// x�� root�� y�� ����
	if (height[x] < height[y]) root[x] = y;
	
	// y�� root�� x�� ����
	else {
		root[y] = x;

		// ���� ���̰� ���ٸ� ��ģ �� (x�� ���� + 1)
		if (height[x] == height[y]) height[x]++;
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// ��� �� N, ��Ƽ �� M, ������ �ƴ� ��� �� trueNum �Է�
	cin >> N >> M >> trueNum;
	person.assign(N + 1, false);
	party.assign(M, vector<int>());

	// ��� ����� ������ �˸� ������ ��Ƽ ����
	if (N == trueNum) {
		cout << 0;
		return 0;
	}

	// ������ �ƴ� ����� ������ ��� ��Ƽ ����
	if (trueNum == 0) {
		cout << M;
		return 0;
	}

	// ������ �ƴ� ��� �Է�
	int num;
	for (int i = 0; i < trueNum; i++) {
		cin >> num;
		truePerson.push_back(num);
	}

	// ��Ƽ �Է�
	int limit;
	for (int i = 0; i < M; i++) {
		cin >> limit;
		for (int j = 0; j < limit; j++) {
			cin >> num;
			party[i].push_back(num);
		}
	}

	// �׷� �з�
	makeSet();
	for (int i = 0; i < M; i++) {
		for (int j = 1; j < party[i].size(); j++) {
			Union(party[i][0], party[i][j]);
		}
	}

	// ������ �ƴ� ��� üũ
	for (int i : truePerson) {
		int idx = Find(i);
		for (int j = 1; j < person.size(); j++) {
			if (Find(j) == idx) person[j] = true;
		}
	}

	// ������ ���� ��Ƽ ī��Ʈ
	int ans = 0;
	for (int i = 0; i < party.size(); i++) {
		bool isAns = true;
		for (int j = 0; j < party[i].size(); j++) {
			if (person[party[i][j]]) {
				isAns = false;
				break;
			}
		}
		if (isAns) ans++;
	}

	// ���� ���
	cout << ans;

	return 0;
}