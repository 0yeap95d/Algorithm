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

	// 알파벳의 위치에 따라 가중치를 부여
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
	
	// 가중치를 기준으로 정렬
	sort(Inp.begin(), Inp.end(), greater<>());

	// 테이블 생성
	int value = 9;
	for (int i = 0; i < 10; i++) {
		if (Inp[i].first == 0) break;
		int idx = Inp[i].second;
		Table[idx] = value--;
	}

	// 0이 될수 없는 알파벳
	for (int i = Inp.size() - 1; i > 0; i--) {
		int idx = Inp[i].second;
		int nextIdx = Inp[i - 1].second;

		if (Table[idx] != 0 || !IsFront[idx]) break;
		swap(Table[idx], Table[nextIdx]);
	}

	// 숫자로 변환 후 더하기
	for (int i = 0; i < N; i++) Ans = Ans + String_To_Num(Words[i]);

	// 정답 출력
	cout << Ans;

	return 0;
}