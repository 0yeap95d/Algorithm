#include <iostream>
#include <queue>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// ������ ���� N
	int N;
	cin >> N;

	// maxQue�� �߰��� ���� ���� ����, minQue�� �߰��� ���� ū ���ڸ� 
	priority_queue<int> maxQue, minQue;
	int inp;
	for (int i = 0; i < N; i++) {
		cin >> inp;

		if (maxQue.size() > minQue.size()) minQue.push(-inp);
		else maxQue.push(inp);

		if (!maxQue.empty() && !minQue.empty()) {
			// maxQue�� �ִ밪�� minQue�� �ּҰ����� ũ�� ��ȯ
			if (maxQue.top() > -minQue.top()) {
				int maxTop = maxQue.top();
				int minTop = minQue.top();

				maxQue.pop();
				minQue.pop();

				maxQue.push(-minTop);
				minQue.push(-maxTop);
			}
		}
		
		// ���� ���
		cout << maxQue.top() << "\n";
	}

	return 0;
}