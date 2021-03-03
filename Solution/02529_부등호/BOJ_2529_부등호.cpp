#include <iostream>
#include <vector>
#define SIZE 10
using namespace std;

int N;
int Sign[SIZE + 2], Ans[SIZE];
bool visited[SIZE];

// �ּ�_ 0���� ���� ����
bool min_DFS(int idx) {
	if (idx >= N + 1) {
		for (int i = 0; i <= N; i++) cout << Ans[i];
		cout << "\n";
		return true;
	}

	for (int i = 0; i < 10; i++) {
		if (visited[i] || (Sign[idx] == 1 && Ans[idx - 1] > i) || (Sign[idx] == -1 && Ans[idx - 1] < i)) continue;

		Ans[idx] = i;
		visited[i] = true;
		if (min_DFS(idx + 1)) return true;
		visited[i] = false;
	}
	return false;
}

// �ִ�_ 9�������� ����
bool max_DFS(int idx) {
	if (idx >= N + 1) {
		for (int i = 0; i <= N; i++) cout << Ans[i];
		cout << "\n";
		return true;
	}

	for (int i = 9; i >= 0; i--) {
		if (visited[i] || (Sign[idx] == 1 && Ans[idx - 1] > i) || (Sign[idx] == -1 && Ans[idx - 1] < i)) continue;

		Ans[idx] = i;
		visited[i] = true;
		if (max_DFS(idx + 1)) return true;
		visited[i] = false;
	}
	return false;
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// �Է�
	cin >> N;
	char ch;
	for (int i = 1; i <= N; i++) {
		cin >> ch;
		if (ch == '<') Sign[i] = 1;
		else Sign[i] = -1;
	}

	// �ִ� 
	max_DFS(0);

	// �ʱ�ȭ
	for (int i = 0; i < SIZE; i++) Ans[i] = visited[i] = 0;

	// �ּ�
	min_DFS(0);

	return 0;
}