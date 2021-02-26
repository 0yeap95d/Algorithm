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

	// s == t 인 경우 
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

		// 아래 두개의 연산은 사용하지 않음
		// 3. s = s / s : 해당 연산의 결과는 무조건 1이므로 최초 한번 나오는것이 최소가 될 수 밖에 없음
		// 4. s = s - s :해당 연산 이후의 모든 값은 0 밖에 나올 수 없으나 t는 0이 될 수 없으므로 사용 x
	}

	cout << Ans;

	return 0;
}