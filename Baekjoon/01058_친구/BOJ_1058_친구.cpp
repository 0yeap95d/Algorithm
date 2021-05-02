#include <iostream>
#define SIZE 51
#define INF 987654321
using namespace std;

int N;
char info[SIZE][SIZE];
int dp[SIZE][SIZE];

void init() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> info[i][j];
			dp[i][j] = i == j ? 0 : info[i][j] == 'N' ? INF : 1;
		}
	}
}

void FloydWarshall() {
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (dp[i][k] + dp[k][j] < dp[i][j]) 
					dp[i][j] = dp[i][k] + dp[k][j];
			}
		}
	}
}

int getMaxFriend() {
	int result = 0;
	for (int i = 0; i < N; i++) {
		int sum = 0;
		for (int j = 0; j < N; j++) 
			if (dp[i][j] != 0 && dp[i][j] <= 2) sum++;
		result = result < sum ? sum : result;
	}
	return result;
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// 초기화
	init();

	// Floyd Warshall 알고리즘
	FloydWarshall();

	// 결과 출력
	cout << getMaxFriend();

	return 0;
}