#include <iostream>
#include <vector>
#include <algorithm>
#define SIZE 1001
using namespace std;

int N;
int Arr[SIZE], Trace[SIZE];
vector<int> Len, Ans;

// 이분 탐색
int Binary_Search(int Start, int End, int Idx) {
	if (Start > End) return Start;

	int Mid = (Start + End) / 2;
	if (Arr[Len[Mid]] == Arr[Idx]) return Mid;
	else if (Arr[Len[Mid]] > Arr[Idx]) return Binary_Search(Start, Mid - 1, Idx);
	else return Binary_Search(Mid + 1, End, Idx);
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// 입력 & Lower_Bound
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> Arr[i];
		int idx = Binary_Search(0, Len.size() - 1, i);
		if (idx >= Len.size()) Len.push_back(i);
		else Len[idx] = i;

		if (idx == 0) Trace[i] = -1;
		else Trace[i] = Len[idx - 1];
	}

	// 역추적
	int idx = Len.back();
	while (idx != -1) {
		Ans.push_back(idx);
		idx = Trace[idx];
	}
	reverse(Ans.begin(), Ans.end());

	// 출력
	cout << Len.size() << "\n";
	for (int ans : Ans) cout << Arr[ans] << " ";

	return 0;
}