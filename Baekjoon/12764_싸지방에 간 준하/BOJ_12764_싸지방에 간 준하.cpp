#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// ����� �� N �Է�
	int N;
	cin >> N;

	// ��ǻ�� �̿� ���� �Է�
	int start, end;
	vector<pair<int, int>> person;
	for (int i = 0; i < N; i++) {
		cin >> start >> end;
		person.push_back({ start, end });
	}

	// ���۽ð� �������� ����
	sort(person.begin(), person.end());

	vector<int> ans;
	priority_queue<int> seat;
	priority_queue<pair<int, int>> que;
	for (auto p : person) {

		// ���� ���� ������ ����� �ð��� ���� ������ �ð����� ���� �� 
		while (!que.empty() && -que.top().first < p.first) {
			seat.push(-que.top().second);
			que.pop();
		}

		// ���� ��ġ ���ϱ�
		int num = ans.size();
		if (seat.empty()) ans.push_back(0);
		else {
			num = -seat.top();
			seat.pop();
		}

		// ������ ����
		ans[num]++;
		que.push({ -p.second, num });
	}

	// ���� ���
	cout << ans.size() << "\n";
	for (int a : ans) cout << a << " ";

	return 0;
}