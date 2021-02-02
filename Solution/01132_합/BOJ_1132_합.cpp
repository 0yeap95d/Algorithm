#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
#define SIZE 50
typedef long long ll;
using namespace std;

int N;
string Words[SIZE];
ll Ans;
vector<pair<ll, int>> Inp(10);
map<int, int> Table;
bool IsFront[10];

ll String_To_Num(string word) {
	ll result = 0;
	for (int i = 0; i < word.size(); i++) {
		int idx = word[i] - 'A';
		result = result * 10 + Table[idx];
	}
	return result;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N;

	// ���ĺ��� ��ġ�� ���� ����ġ�� �ο�
	for (int i = 0; i < N; i++) {
		cin >> Words[i];

		ll weight = 1;
		for (int j = Words[i].size() - 1; j >= 0; j--) {
			int idx = Words[i][j] - 'A';
			Inp[idx].first += weight;
			Inp[idx].second = idx;
			weight = weight * 10;
			if (j == 0) IsFront[idx] = true;
		}
	}
	
	// ����ġ�� �������� ����
	sort(Inp.begin(), Inp.end(), greater<>());

	// ���̺� ����
	int value = 9;
	for (int i = 0; i < 10; i++) {
		if (Inp[i].first == 0) break;
		int idx = Inp[i].second;
		Table[idx] = value--;
	}

	// 0�� �ɼ� ���� ���ĺ�
	for (int i = Inp.size() - 1; i > 0; i--) {
		int idx = Inp[i].second;
		int nextIdx = Inp[i - 1].second;

		if (Table[idx] != 0 || !IsFront[idx]) break;
		swap(Table[idx], Table[nextIdx]);
	}

	// ���ڷ� ��ȯ �� ���ϱ�
	for (int i = 0; i < N; i++) Ans = Ans + String_To_Num(Words[i]);

	// ���� ���
	cout << Ans;

	return 0;
}