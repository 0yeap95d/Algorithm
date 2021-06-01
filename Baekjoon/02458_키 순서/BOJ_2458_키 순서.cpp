#include <iostream>
#define MAX 505
#define INF 987654321
using namespace std;

int N, M;
int students[MAX][MAX];

void Init() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i != j) students[i][j] = INF;
		}
	}

	int stu1, stu2;
	for (int i = 0; i < M; i++) {
		cin >> stu1 >> stu2;
		students[stu1][stu2] = 1;
	}
}

void Floyd() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (students[i][j] > students[i][k] + students[k][j])
					students[i][j] = students[i][k] + students[k][j];
			}
		}
	}
}

int getCntStu() {
	int res = N;
	for (int i = 1; i <= N; i++) {
		bool isSuccess = true;
		for (int j = 1; j <= N; j++) {
			if (students[i][j] == INF && students[j][i] == INF) {
				res--;
				break;
			}
		}
	}
	return res;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	Init();
	Floyd();
	cout << getCntStu();

	return 0;
}