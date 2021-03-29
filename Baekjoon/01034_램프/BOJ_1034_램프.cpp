#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define SIZE 50
using namespace std;

int N, M, K, Ans;
vector<string> Lamps;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> M;
	
	Lamps.resize(N);
	for (int i = 0; i < N; i++) cin >> Lamps[i];
	cin >> K;

	sort(Lamps.begin(), Lamps.end());

	int sameLamp = 0;
	for (int i = 0; i < N; i++) {

		// 같은 행이 얼마나 연속되는지 카운트
		sameLamp++;
		if (i != N -1 && Lamps[i] == Lamps[i + 1]) continue;
		
		// 행에서 꺼져있는 램프 갯수 카운트
		int offLamp = 0;
		for (int j = 0; j < M; j++) 
			if (Lamps[i][j] == '0') offLamp++;
		

		// 행을 모두 켜지게 할 수 있는지 체크
		if (offLamp <= K && (K - offLamp) % 2 == 0) Ans = max(Ans, sameLamp);

		sameLamp = 0;
	}

	cout << Ans;
	
	return 0;
}