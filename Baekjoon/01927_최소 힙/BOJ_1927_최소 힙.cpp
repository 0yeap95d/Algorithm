#include <iostream>
#include <queue>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// 연산의 개수 N 입력
	int N;
	cin >> N;

	// 우선순위 큐
	priority_queue<int> pq;
	int inp, ans;

	for (int i = 0; i < N; i++) {
		// 연산 입력
		cin >> inp;
	
		// 입력이 0 일때
		if (inp == 0) {
			// 큐가 비어있으면 0, 아니면 가장 작은 값 출력
			ans = 0;
			if (!pq.empty()) {
				ans = -pq.top();
				pq.pop();
			}
			cout << ans << "\n";
		}

		// 입력이 0이 아닐 떄 큐 삽입
		else pq.push(-inp);
	}

	return 0;
}