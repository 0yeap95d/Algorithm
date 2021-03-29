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

	// 두 값의 root가 같으면 이미 같은 트리
	if (x == y) return;

	// x의 root를 y로 변경
	if (height[x] < height[y]) root[x] = y;
	
	// y의 root를 x로 변경
	else {
		root[y] = x;

		// 만약 높이가 같다면 합친 후 (x의 높이 + 1)
		if (height[x] == height[y]) height[x]++;
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// 사람 수 N, 파티 수 M, 진실을 아는 사람 수 trueNum 입력
	cin >> N >> M >> trueNum;
	person.assign(N + 1, false);
	party.assign(M, vector<int>());

	// 모든 사람이 진실을 알면 가능한 파티 없음
	if (N == trueNum) {
		cout << 0;
		return 0;
	}

	// 진실을 아는 사람이 없으면 모든 파티 가능
	if (trueNum == 0) {
		cout << M;
		return 0;
	}

	// 진실을 아는 사람 입력
	int num;
	for (int i = 0; i < trueNum; i++) {
		cin >> num;
		truePerson.push_back(num);
	}

	// 파티 입력
	int limit;
	for (int i = 0; i < M; i++) {
		cin >> limit;
		for (int j = 0; j < limit; j++) {
			cin >> num;
			party[i].push_back(num);
		}
	}

	// 그룹 분류
	makeSet();
	for (int i = 0; i < M; i++) {
		for (int j = 1; j < party[i].size(); j++) {
			Union(party[i][0], party[i][j]);
		}
	}

	// 진실을 아는 사람 체크
	for (int i : truePerson) {
		int idx = Find(i);
		for (int j = 1; j < person.size(); j++) {
			if (Find(j) == idx) person[j] = true;
		}
	}

	// 거짓말 가능 파티 카운트
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

	// 정답 출력
	cout << ans;

	return 0;
}