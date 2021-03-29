#include <iostream>
#include <queue>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// 카드의 개수 N
	int N;
	cin >> N;

	// 카드 순서대로 push
	queue<int> que;
	for (int i = 1; i <= N; i++) que.push(i);

	while (!que.empty()) {
		// 위의 숫자 출력
		cout << que.front() << " ";
		que.pop();

		if (que.empty()) break;
		
		// 다음 숫자 아래로
		que.push(que.front());
		que.pop();
	}

	return 0;
}