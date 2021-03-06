#include <iostream>
#include <queue>
#include <cstring>
#define SIZE 20001
using namespace std;

int testcase;
int num;
bool visited[SIZE];
queue<pair<int, string>> que;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> testcase;

	while (testcase--) {
		cin >> num;
		
		if (num == 1) {
			cout << "1\n";
			continue;
		}

		// 변수 초기화
		memset(visited, 0, sizeof(visited));
		while (!que.empty()) que.pop();
		que.push({ 1, "1" });

		while (!que.empty()) {
			int n = que.front().first;
			string s = que.front().second;
			que.pop();

			// 정답
			if (n == 0) {
				cout << s << "\n";
				break;
			}

			// 수의 길이가 100을 넘을때
			if (s.size() > 100) {
				cout << "BRAK\n";
				break;
			}

			// 숫자 뒤에 0 추가
			int nextNum1 = (n * 10) % num;
			string nextStr1 = s + "0";
			if (!visited[nextNum1]) {
				que.push({ nextNum1, nextStr1 });
				visited[nextNum1] = true;
			}

			// 숫자 뒤에 1 추가
			int nextNum2 = (n * 10 + 1) % num;
			string nextStr2 = s + "1";
			if (!visited[nextNum2]) {
				que.push({ nextNum2, nextStr2 });
				visited[nextNum2] = true;
			}
		}
	}

	return 0;
}