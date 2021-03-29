#include <iostream>
#include <queue>
#include <map>
using namespace std;

struct Stone {
	int A;
	int B;
	int C;
};

bool operator<(Stone s1, Stone s2) {
	if (s1.A == s2.A) {
		if (s1.B == s2.B) return s1.C > s2.C;
		return s1.B > s2.B;
	}
	return s1.A > s2.A;
}

int Ans;
Stone stone;
map<Stone, bool> visited;
queue<Stone> que;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// 그룹 별 돌 개수 입력
	cin >> stone.A >> stone.B >> stone.C;


	// 두 그룹 정하기
	que.push(stone);
	visited[stone] = true;

	while (!que.empty()) {
		int a = que.front().A;
		int b = que.front().B;
		int c = que.front().C;
		que.pop();

		if (a == b && b == c) {
			Ans = 1;
			break;
		}

		// A, B
		int x, y;
		if (a > b) {
			x = a - b, y = b + b;
			Stone temp = { x, y, c };
			if (!visited[temp]) {
				visited[temp] = true;
				que.push(temp);
			}
		}
		else if (a < b) {
			x = a + a, y = b - a;
			Stone temp = { x, y, c };
			if (!visited[temp]) {
				visited[temp] = true;
				que.push(temp);
			}
		}

		// A, C
		if (a > c) {
			x = a - c, y = c + c;
			Stone temp = { x, b, y };
			if (!visited[temp]) {
				visited[temp] = true;
				que.push(temp);
			}
		}
		else if (a < c) {
			x = a + a, y = c - a;
			Stone temp = { x, b, y };
			if (!visited[temp]) {
				visited[temp] = true;
				que.push(temp);
			}
		}
		
		// B, C
		if (b > c) {
			x = b - c, y = c + c;
			Stone temp = { a, x, y };
			if (!visited[temp]) {
				visited[temp] = true;
				que.push(temp);
			}
		}
		else if (b < c) {
			x = b + b, y = c - b;
			Stone temp = { a, x, y };
			if (!visited[temp]) {
				visited[temp] = true;
				que.push(temp);
			}
		}
	}

	cout << Ans;

	return 0;
}