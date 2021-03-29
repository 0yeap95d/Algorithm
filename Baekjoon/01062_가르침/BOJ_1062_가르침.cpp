#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

// 사용할 알파벳
bool visited[26];
int N, K, ans;
vector<string> word;

int learnWord() {
	int ret = 0;
	for (string w : word) {
		bool isLearn = true;
		for (int i = 0; i < w.size(); i++) {
			if (!visited[w[i] - 'a']) {
				isLearn = false;
				break;
			}
		}
		if (isLearn) ret++;
	}
	return ret;
}

void DFS(int idx, int cnt) {
	// 알파벳 중 K가지 선택
	if (cnt == K) {
		ans = max(ans, learnWord());
		return;
	}

	for (int i = idx; i < 26; i++) {
		if (visited[i]) continue;

		visited[i] = true;
		DFS(i + 1, cnt + 1);
		visited[i] = false;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> K;

	// 가르칠 수 있는 글자의 갯수가 5개 아래면 아무것도 읽을 수 없음 
	string check = "acint";
	if (K < check.size()) {
		cout << 0;
		return 0;
	}

	// 배울 수 있는 글자가 26개 이상이면 모든 단어를 배울 수 있음
	if (K >= 26) {
		cout << N;
		return 0;
	}

	// 앞뒤에 붙는 단어를 미리 처리
	K -= check.size();
	for (int i = 0; i < check.size(); i++) visited[check[i] - 'a'] = true;

	// 문자열 입력받고 사용되는 알파벳 체크
	string inp;
	for (int i = 0; i < N; i++) {
		cin >> inp;
		word.push_back(inp.substr(4, inp.size() - 8));
	}

	// 사용되는 알파벳 중에서 K개의 알파벳을 고르고, 배울 수 있는 단어갯수 확인
	DFS(0, 0);

	// 정답 출력
	cout << ans;

	return 0;
}