#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// 사람의 수 N 입력
	int N;
	cin >> N;

	// 컴퓨터 이용 정보 입력
	int start, end;
	vector<pair<int, int>> person;
	for (int i = 0; i < N; i++) {
		cin >> start >> end;
		person.push_back({ start, end });
	}

	// 시작시간 기준으로 정렬
	sort(person.begin(), person.end());

	vector<int> ans;
	priority_queue<int> seat;
	priority_queue<pair<int, int>> que;
	for (auto p : person) {

		// 제일 빨리 끝나는 사람의 시간이 새로 들어오는 시간보다 작을 때 
		while (!que.empty() && -que.top().first < p.first) {
			seat.push(-que.top().second);
			que.pop();
		}

		// 앉을 위치 정하기
		int num = ans.size();
		if (seat.empty()) ans.push_back(0);
		else {
			num = -seat.top();
			seat.pop();
		}

		// 싸지방 시작
		ans[num]++;
		que.push({ -p.second, num });
	}

	// 정답 출력
	cout << ans.size() << "\n";
	for (int a : ans) cout << a << " ";

	return 0;
}