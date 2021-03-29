#include <iostream>
#include <map>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int testCase, F;
map<string, int> mapping;
map<int, int> cnt;
vector<int> parents;

void Make_Set(int size) {
	parents.resize(size);
	for (int i = 1; i < size; i++) {
		cnt[i] = 1;
		parents[i] = i;
	}
}

int Find_Parent(int x) {
	if (parents[x] == x) return x;
	else return parents[x] = Find_Parent(parents[x]);
}

int Union_Parent(int x, int y) {
	x = Find_Parent(x);
	y = Find_Parent(y);

	if (x == y) return cnt[x];
	
	cnt[y] += cnt[x];
	cnt[x] = 0;
	parents[x] = y;

	return cnt[y];
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> testCase;

	while (testCase--) {
		cin >> F;
		mapping.clear();
		cnt.clear();

		// 친구 입력, 이름을 번호로 바꿔서 저장
		int num = 1;
		string inp1, inp2;
		vector<pair<int, int>> networks;
		for (int i = 0; i < F; i++) {
			cin >> inp1 >> inp2;
			if (mapping[inp1] == 0) mapping[inp1] = num++;
			if (mapping[inp2] == 0) mapping[inp2] = num++;
			networks.push_back({ mapping[inp1], mapping[inp2] });
		}

		// parents 배열 만들기
		Make_Set(num);

		for (pair<int, int> network : networks) {
			// 친구 네트워크 연결
			cout << Union_Parent(network.first, network.second) << "\n";
		}
	}

	return 0;
}