#include <iostream>
#include <map>
#define SIZE 100005
using namespace std;

int n;
int inOrder[SIZE];
int postOrder[SIZE];
map<int, int> idxInOrder;

void makePreOrder(int inStart, int inEnd, int postStart, int postEnd) {

	int num = postOrder[postEnd];
	postOrder[postEnd] = 0;
	if (num == 0) return;

	cout << num << " ";

	int inMid = idxInOrder[num];

	int leftSize = inMid - inStart - 1;
	int rightSize = inEnd - inMid - 1;

	int leftPostStart = postStart;
	int leftPostEnd = leftPostStart + leftSize;
	int rightPostStart = leftPostEnd + 1;
	int rightPostEnd = rightPostStart + rightSize;

	makePreOrder(inStart, inMid - 1, leftPostStart, leftPostEnd);
	makePreOrder(inMid + 1, inEnd, rightPostStart, rightPostEnd);
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// ������ ���� n
	cin >> n;

	// �ο���, �ο����ε��� map<����, �ε���>
	for (int i = 0; i < n; i++) {
		cin >> inOrder[i];
		idxInOrder[inOrder[i]] = i;
	}

	// ����Ʈ����
	for (int i = 0; i < n; i++) cin >> postOrder[i];

	// ��������
	makePreOrder(0, n - 1, 0, n - 1);

	return 0;
}