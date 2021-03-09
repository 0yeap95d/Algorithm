#include <iostream>
#define SIZE 1001
using namespace std;

int T, N;
bool gear[SIZE][8];
bool visited[SIZE];

int countS() {
	int result = 0;
	for (int i = 0; i < T; i++) {
		if (gear[i][0]) result++;
	}
	return result;
}

void rotate(int num, int dir) {
	// 시계 방향
	if (dir == 1) {
		int temp = gear[num][7];
		for (int i = 7; i > 0; i--) 
			gear[num][i] = gear[num][i - 1];
		gear[num][0] = temp;
	}

	// 반시계 방향
	else {
		int temp = gear[num][0];
		for (int i = 0; i < 7; i++) 
			gear[num][i] = gear[num][i + 1]; 
		gear[num][7] = temp;
	}
}

void moveGear(int num, int dir) {
	visited[num] = true;

	// 왼쪽기어와 극이 같을 때
	if (num > 0 && !visited[num - 1] && gear[num][6] != gear[num - 1][2]) {
		moveGear(num - 1, dir * -1);
	}
	
	// 오른쪽 기어와 극이 같을 때
	if (num < T - 1 && !visited[num + 1] && gear[num][2] != gear[num + 1][6]) {
		moveGear(num + 1, dir * -1);
	}

	// 기어 회전
	rotate(num, dir);
	visited[num] = false;
}


int main() {

	ios_base::sync_with_stdio(false); 
	cin.tie(NULL), cout.tie(NULL);

	cin >> T;

	char inp;
	for (int i = 0; i < T; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> inp;
			if (inp == '0') gear[i][j] = false;
			else gear[i][j] = true;
		}
	}

	cin >> N;
	int num, dir;
	for (int i = 0; i < N; i++) {
		cin >> num >> dir;
		moveGear(num - 1, dir);
	}

	cout << countS();

	return 0;
}