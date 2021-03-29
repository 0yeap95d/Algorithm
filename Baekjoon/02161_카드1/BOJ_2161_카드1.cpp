#include <iostream>
#include <queue>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// ī���� ���� N
	int N;
	cin >> N;

	// ī�� ������� push
	queue<int> que;
	for (int i = 1; i <= N; i++) que.push(i);

	while (!que.empty()) {
		// ���� ���� ���
		cout << que.front() << " ";
		que.pop();

		if (que.empty()) break;
		
		// ���� ���� �Ʒ���
		que.push(que.front());
		que.pop();
	}

	return 0;
}