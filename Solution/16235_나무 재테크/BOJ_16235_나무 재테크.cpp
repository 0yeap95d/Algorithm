#include <iostream>
#include <queue>
#define SIZE 10
using namespace std;

int N, M, K;
int Add[SIZE][SIZE];
int Nutrients[SIZE][SIZE];
queue<pair<int, int>> spreadTree;
priority_queue<int, vector<int>, greater<int>> tree[SIZE][SIZE];

int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

// 입력 및 초기값 설정
void Init() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Add[i][j];
			Nutrients[i][j] = 5;
		}
	}

	int x, y, z;
	for (int i = 0; i < M; i++) {
		cin >> x >> y >> z;
		tree[x - 1][y - 1].push(z);
	}
}

// 봄, 여름 - 양분섭취, 죽은나무 -> 양분
void SpringAndSummer() {
	
	queue<int> temp;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			
			int addNutrients = 0;
			while (!tree[i][j].empty()) {
				int age = tree[i][j].top();
				tree[i][j].pop();
				
				// 양분이 부족한 나무
				if (Nutrients[i][j] < age) addNutrients += age / 2;
				
				// 양분 섭취
				else {
					Nutrients[i][j] = Nutrients[i][j] - age;
					temp.push(age + 1);
					
					// 나이가 5의 배수일 때
					if ((age + 1) % 5 == 0) spreadTree.push({ i, j });
				}
			}

			// 죽은 나무가 양분으로 추가
			Nutrients[i][j] += addNutrients;

			// 
			while (!temp.empty()) {
				tree[i][j].push(temp.front());
				temp.pop();
			}
		}
	}
}


// 가을 - 나무 번식
void Autumn() {
	while (!spreadTree.empty()) {
		int x = spreadTree.front().first;
		int y = spreadTree.front().second;
		spreadTree.pop();

		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			tree[nx][ny].push(1);
		}
	}
}


// 겨울 - 양분 추가
void Winter() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			Nutrients[i][j] = Nutrients[i][j] + Add[i][j];
		}
	}
}

// 나무의 개수 카운트
int countTree() {
	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			result = result + tree[i][j].size();
		}
	}
	return result;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	Init();

	for (int i = 0; i < K; i++) {
		SpringAndSummer();
		Autumn();
		Winter();
	}

	cout << countTree();

	return 0;
}