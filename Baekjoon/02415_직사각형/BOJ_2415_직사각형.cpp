#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;

struct Info {
	ll dist;
	ll midX;
	ll midY;
	int idxP1;
	int idxP2;
};

bool cmp(const Info& i1, const Info& i2) {
	if (i1.dist != i2.dist) return i1.dist < i2.dist;
	if (i1.midX != i2.midX) return i1.midX < i2.midX;
	return i1.midY < i2.midY;
}

int N;
ll Answer;
vector<pair<ll, ll>> pos;
vector<Info> infos;

ll getDist(int idx1, int idx2) {
	ll dist1 = (pos[idx1].first - pos[idx2].first) * (pos[idx1].first - pos[idx2].first);
	ll dist2 = (pos[idx1].second - pos[idx2].second) * (pos[idx1].second - pos[idx2].second);
	return  dist1 + dist2;
}

// 신발끈 공식
ll getArea(int a, int b, int c, int d) {
	ll area = abs(
		pos[a].first * pos[c].second +
		pos[c].first * pos[b].second +
		pos[b].first * pos[d].second +
		pos[d].first * pos[a].second -
		pos[c].first * pos[a].second -
		pos[b].first * pos[c].second -
		pos[d].first * pos[b].second -
		pos[a].first * pos[d].second) / 2;
	return area;
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// 점의 개수 N
	cin >> N;

	// 좌표 입력
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		pos.push_back({ x, y });
	}

	// 두 정점으로 만들 수 있는 모든 거리정보
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			Info info;
			info.dist = getDist(i, j);
			info.midX = pos[i].first + pos[j].first;
			info.midY = pos[i].second + pos[j].second;
			info.idxP1 = i;
			info.idxP2 = j;
			infos.push_back(info);
		}
	}

	// 대각선 길이별 정렬
	sort(infos.begin(), infos.end(), cmp);

	int maxSize = infos.size();
	for (int i = 0; i < maxSize - 1; i++) {
		for (int j = i + 1; j < maxSize; j++) {
			Info cur = infos[i];
			Info next = infos[j];
			if (cur.dist != next.dist || cur.midX != next.midX || cur.midY != next.midY) break;
			Answer = max(Answer, getArea(cur.idxP1, cur.idxP2, next.idxP1, next.idxP2));
		}
	}

	cout << Answer;

	return 0;
}