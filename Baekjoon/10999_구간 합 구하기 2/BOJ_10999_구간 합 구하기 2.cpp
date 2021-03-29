#include <iostream>
#include <vector>
#include <cmath>
#define SIZE 1000010
typedef long long ll;

using namespace std;

int N, M, K;
int inp[SIZE];
vector<ll> SegmentTree, Lazy;

void setSegmentTree() {
	// SegmentTree, Lazy ũ�� ����
	int treeHeight = (int)ceil(log2(N));
	int treeSize = (1 << (treeHeight + 1));
	SegmentTree.resize(treeSize);
	Lazy.resize(treeSize);
}

ll makeSegmentTree(int idx, int start, int end) {
	if (start == end) return SegmentTree[idx] = inp[start];

	int mid = (start + end) / 2;
	ll left = makeSegmentTree(idx * 2, start, mid);
	ll right = makeSegmentTree(idx * 2 + 1, mid + 1, end);
	SegmentTree[idx] = left + right;

	return SegmentTree[idx];
}

void Lazy_Update(int idx, int start, int end) {
	// �����ؾ� �� ���� ���� ��
	if (Lazy[idx] == 0) return;
	SegmentTree[idx] = SegmentTree[idx] + (end - start + 1) * Lazy[idx];

	// ������尡 �ƴ϶�� ���� ��忡 Lazy���� ����
	if (start != end) {
		Lazy[idx * 2] = Lazy[idx * 2] + Lazy[idx];
		Lazy[idx * 2 + 1] = Lazy[idx * 2 + 1] + Lazy[idx];
	}

	// ���� ����� Lazy���� ��������Ƿ� 0���� �ٲ�
	Lazy[idx] = 0;
}

void Update(int idx, int start, int end, int left, int right, ll value) {
	
	// Lazy���� �ִٸ� ������Ʈ
	Lazy_Update(idx, start, end);

	// �����ϰ��� �ϴ� ������ ����� ��
	if (right < start || end < left) return;

	// �����ϰ��� �ϴ� ���� �̳��� ���� ��
	if (left <= start && end <= right) {
		SegmentTree[idx] = SegmentTree[idx] + (end - start + 1) * value;
		if (start != end) {
			Lazy[idx * 2] = Lazy[idx * 2] + value;
			Lazy[idx * 2 + 1] = Lazy[idx * 2 + 1] + value;
		}
		return;
	}

	// �����ϰ����ϴ� ������ ����� �ٽ� Ž�� �� ���� �� ����
	int mid = (start + end) / 2;
	Update(idx * 2, start, mid, left, right, value);
	Update(idx * 2 + 1, mid + 1, end, left, right, value);
	SegmentTree[idx] = SegmentTree[idx * 2] + SegmentTree[idx * 2 + 1];
}

ll Query(int idx, int start, int end, int left, int right) {
	
	// Lazy���� �ִٸ� ������Ʈ
	Lazy_Update(idx, start, end);

	// ã���� �ϴ� ������ ����� ��
	if (right < start || end < left) return 0;

	// ã���� �ϴ� ���� �̳��� ���� ��
	if (left <= start && end <= right) return SegmentTree[idx];

	// ã�����ϴ� ������ ����� �ٽ� Ž��
	int mid = (start + end) / 2;
	ll Left_Result = Query(idx * 2, start, mid, left, right);
	ll Right_Result = Query(idx * 2 + 1, mid + 1, end, left, right);
	return Left_Result + Right_Result;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) cin >> inp[i];

	setSegmentTree();
	makeSegmentTree(1, 0, N - 1);

	int a, b, c, d;
	for (int i = 0; i < M + K; i++) {
		cin >> a;
		if (a == 1) {
			cin >> b >> c >> d;
			Update(1, 0, N - 1, b - 1, c - 1, d);
		}
		else {
			cin >> b >> c;
			cout << Query(1, 0, N - 1, b - 1, c - 1) << "\n";
		}
	}

	return 0;
}