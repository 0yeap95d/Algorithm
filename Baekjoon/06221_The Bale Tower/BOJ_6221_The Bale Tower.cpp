#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int>> bales;
vector<int> tower;

void init() {
	// �Է� (N: bale ����)
	cin >> N;
	bales.resize(N);
	for (int i = 0; i < N; i++)
		cin >> bales[i].first >> bales[i].second;
	
	// ����
	sort(bales.begin(), bales.end());
}

void stackBales() {
	// Lower Bound �̿��ؼ� Bale �ױ�
	for (auto bale : bales) {
		int idx = lower_bound(tower.begin(), tower.end(), bale.second) - tower.begin();
		if (tower.size() == idx) tower.push_back(bale.second);
		else tower[idx] = bale.second;
	}
}

int main() {
	
	init();
	stackBales();
	cout << tower.size();

	return 0;
}