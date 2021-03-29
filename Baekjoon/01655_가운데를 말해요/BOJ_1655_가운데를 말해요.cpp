#include <iostream>
#include <queue>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// 정수의 개수 N
	int N;
	cin >> N;

	// maxQue는 중간값 보다 작은 숫자, minQue는 중간값 보다 큰 숫자만 
	priority_queue<int> maxQue, minQue;
	int inp;
	for (int i = 0; i < N; i++) {
		cin >> inp;

		if (maxQue.size() > minQue.size()) minQue.push(-inp);
		else maxQue.push(inp);

		if (!maxQue.empty() && !minQue.empty()) {
			// maxQue의 최대값이 minQue의 최소값보다 크면 교환
			if (maxQue.top() > -minQue.top()) {
				int maxTop = maxQue.top();
				int minTop = minQue.top();

				maxQue.pop();
				minQue.pop();

				maxQue.push(-minTop);
				minQue.push(-maxTop);
			}
		}
		
		// 정답 출력
		cout << maxQue.top() << "\n";
	}

	return 0;
}