#include <iostream>
#include <cstring>
#include <cmath>
#include <map>
#include <cstdlib>
#define SIZE 10000000
using namespace std;

int testcase, answer;
int cntNum[10];
bool Prime[SIZE];
map<string, bool> check;
map<int, bool> visited;

void setting_Prime() {
	Prime[0] = Prime[1] = true;
	for (int i = 2; i < sqrt(SIZE); i++) {
		if (Prime[i]) continue;
		for (int j = 2; i * j < SIZE; j++) Prime[i * j] = true;
	}
}

void make_Num(string num) {
	for (int i = 0; i < 10; i++) {
		if (cntNum[i] == 0) continue;

		string str = num + (char)(i + '0');
		int idx = atoi(str.c_str());

		if (check[str]) continue;
		check[str] = true;
		cntNum[i]--;
		if (!Prime[idx] && !visited[idx]) {
			answer++;
			visited[idx] = true;
		}
		make_Num(str);
		cntNum[i]++;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// 소수 배열 만들기
	setting_Prime();

	cin >> testcase;
	string num;
	while (testcase--) {
		// 변수 초기화
		answer = 0;
		check.clear(), visited.clear();
		for (int i = 0; i < 10; i++) cntNum[i] = 0;

		// 입력
		cin >> num;
		for (char c : num) cntNum[c - '0']++;

		// 조합
		make_Num("");

		// 출력
		cout << answer << "\n";
	}

	return 0;
}