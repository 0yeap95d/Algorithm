#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

// ����� ���ĺ�
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
	// ���ĺ� �� K���� ����
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

	// ����ĥ �� �ִ� ������ ������ 5�� �Ʒ��� �ƹ��͵� ���� �� ���� 
	string check = "acint";
	if (K < check.size()) {
		cout << 0;
		return 0;
	}

	// ��� �� �ִ� ���ڰ� 26�� �̻��̸� ��� �ܾ ��� �� ����
	if (K >= 26) {
		cout << N;
		return 0;
	}

	// �յڿ� �ٴ� �ܾ �̸� ó��
	K -= check.size();
	for (int i = 0; i < check.size(); i++) visited[check[i] - 'a'] = true;

	// ���ڿ� �Է¹ް� ���Ǵ� ���ĺ� üũ
	string inp;
	for (int i = 0; i < N; i++) {
		cin >> inp;
		word.push_back(inp.substr(4, inp.size() - 8));
	}

	// ���Ǵ� ���ĺ� �߿��� K���� ���ĺ��� ����, ��� �� �ִ� �ܾ�� Ȯ��
	DFS(0, 0);

	// ���� ���
	cout << ans;

	return 0;
}