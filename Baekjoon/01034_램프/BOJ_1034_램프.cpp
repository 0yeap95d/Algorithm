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

		// ���� ���� �󸶳� ���ӵǴ��� ī��Ʈ
		sameLamp++;
		if (i != N -1 && Lamps[i] == Lamps[i + 1]) continue;
		
		// �࿡�� �����ִ� ���� ���� ī��Ʈ
		int offLamp = 0;
		for (int j = 0; j < M; j++) 
			if (Lamps[i][j] == '0') offLamp++;
		

		// ���� ��� ������ �� �� �ִ��� üũ
		if (offLamp <= K && (K - offLamp) % 2 == 0) Ans = max(Ans, sameLamp);

		sameLamp = 0;
	}

	cout << Ans;
	
	return 0;
}