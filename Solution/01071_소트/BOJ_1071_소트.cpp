#include <iostream>
#include <vector>
#include <algorithm>
#define SIZE 1002
using namespace std;

int N, Max_Val, Min_Val = SIZE;
int Count_Num[SIZE];

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N;
	int inp;
	for (int i = 0; i < N; i++) {
		cin >> inp;
		Count_Num[inp]++;
		Max_Val = max(Max_Val, inp);
		Min_Val = min(Min_Val, inp);
	}

	for (int i = Min_Val; i <= Max_Val; i++) {

		if (Count_Num[i] <= 0) continue;

		// 연속된 값이 존재하지 않을 때
		if (Count_Num[i + 1] <= 0) while (Count_Num[i]--) cout << i << " ";
		
		// 연속된 값이 존재할 때
		else {
			// 사이에 들어갈 값 찾기
			int temp = -1;
			for (int j = i + 2; j <= Max_Val; j++) {
				if (Count_Num[j] == 0) continue;
				temp = j;
				break;
			}

			// 존재하지 않을 때
			if (temp == -1) {
				while (Count_Num[i + 1]--) cout << i + 1 << " ";
				while (Count_Num[i]--) cout << i << " ";
			}

			// 존재할 때
			else {
				while (Count_Num[i]--) cout << i << " ";
				Count_Num[temp]--;
				cout << temp << " ";
			}
		}
	}

	return 0;
}