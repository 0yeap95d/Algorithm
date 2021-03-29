#include <iostream>
#include <cstring>
#include <queue>
#include <map>
typedef long long ll;
using namespace std;

ll s, t;
queue<pair<ll, string>> que;
string Ans = "-1";
map<ll, bool> visited;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> s >> t;

	// s == t �� ��� 
	if (s == t) {
		cout << 0;
		return 0;
	}

	if (s * s <= t) {
		que.push({ s * s, "*" });
		visited[s * s] = true;
	}
	if (s + s <= t) {
		que.push({ s + s, "+" });
		visited[s + s] = true;
	}

	que.push({ 1, "/" });
	visited[1] = true;

	while (!que.empty()) {
		ll num = que.front().first;
		string oper = que.front().second;
		que.pop();

		if (num == t) {
			Ans = oper;
			break;
		}

		// 1. s = s * s
		if (num * num <= t && !visited[num * num]) {
			que.push({ num * num, oper + "*" });
			visited[num * num] = true;
		}

		// 2. s = s + s
		if (num + num <= t && !visited[num + num]) {
			que.push({ num + num, oper + "+" });
			visited[num + num] = true;
		}

		// �Ʒ� �ΰ��� ������ ������� ����
		// 3. s = s / s : �ش� ������ ����� ������ 1�̹Ƿ� ���� �ѹ� �����°��� �ּҰ� �� �� �ۿ� ����
		// 4. s = s - s :�ش� ���� ������ ��� ���� 0 �ۿ� ���� �� ������ t�� 0�� �� �� �����Ƿ� ��� x
	}

	cout << Ans;

	return 0;
}