#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define MAX 1001

using namespace std;

int N, M;
int old[MAX];
int cnt[MAX];
vector<int> rec, ans;
set<int> frame;

void input() {
	cin >> N >> M;
	rec.resize(M);
	for (int i = 0; i < M; i++)
		cin >> rec[i];
}

int getLeastNum() {
	int minIdx = -1;
	int minVal = MAX;
	int oldOrd = MAX;
	for (int num : frame) {		
		if (cnt[num] < minVal || (cnt[num] == minVal && old[num] < oldOrd)) {
			minIdx = num;
			minVal = cnt[num];
			oldOrd = old[num];
		}
	}
	return minIdx;
}

void deleteFromFrame() {
	int num = getLeastNum();
	frame.erase(num);
	old[num] = cnt[num] = 0;
}

void addToFrame(int num) {
	if (frame.find(num) == frame.end()) {
		if (frame.size() >= N) deleteFromFrame();
		frame.insert(num);
	}
	cnt[num]++;
}

void print() {
	for (int num : frame) ans.push_back(num);
	sort(ans.begin(), ans.end());
	for (int num : ans) cout << num << ' ';
}

void solution() {
	input();
	for (int i = 0; i < M; i++) {
		int num = rec[i];
		addToFrame(num);
		if (old[num] == 0) old[num] = i + 1;
	}
	print();
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	solution();

	return 0;
}