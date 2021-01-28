#include <iostream>
#include <vector>
#include <map>
#define SIZE 12
using namespace std;

struct Piece {
	int num;
	int x;
	int y;
	int z;
	int dir;
};

int N, K;
int Board[SIZE][SIZE];
vector<Piece> Chess[SIZE][SIZE];
map<int, Piece> Pos;

int dx[5] = { 0, 0, 0, -1, 1 };
int dy[5] = { 0, 1, -1, 0, 0 };

// ���� ��ȯ
int changeDir(int dir) {
	if (dir % 2 == 0) return dir - 1;
	return dir + 1;
}

bool rangeCheck(int nx, int ny) {
	return nx < 0 || nx >= N || ny < 0 || ny >= N;
}

// �̵��� ĭ�� ������
void RedPoint(Piece piece, int nx, int ny) {
	int size = Chess[piece.x][piece.y].size();
	for (int i = size - 1; i >= piece.z; i--) {
		int n = Chess[piece.x][piece.y][i].num;
		Pos[n].x = nx, Pos[n].y = ny, Pos[n].z = Chess[nx][ny].size();

		Chess[nx][ny].push_back(Pos[n]);
		Chess[piece.x][piece.y].pop_back();
	}
}

// �̵��� ĭ�� ���
void WhitePoint(Piece piece, int nx, int ny) {
	int size = Chess[piece.x][piece.y].size();
	for (int i = piece.z; i < size; i++) {
		int n = Chess[piece.x][piece.y][i].num;
		Pos[n].x = nx, Pos[n].y = ny, Pos[n].z = Chess[nx][ny].size();
		Chess[nx][ny].push_back(Pos[n]);
	}
	for (int i = piece.z; i < size; i++) {
		Chess[piece.x][piece.y].pop_back();
	}
}

// �̵�
bool movePiece(int num) {
	
	Piece piece = Pos[num];

	int nx = piece.x + dx[piece.dir];
	int ny = piece.y + dy[piece.dir];

	// ������ ����ų� ���� ĭ�� �Ķ����� ���
	if (rangeCheck(nx, ny) || Board[nx][ny] == 2) {
		Chess[piece.x][piece.y][piece.z].dir = Pos[num].dir = piece.dir = changeDir(piece.dir);
		nx = piece.x + dx[piece.dir];
		ny = piece.y + dy[piece.dir];

		if (!rangeCheck(nx, ny) && Board[nx][ny] != 2) {
			if (Board[nx][ny] == 1) RedPoint(piece, nx, ny);
			else if (Board[nx][ny] == 0) WhitePoint(piece, nx, ny);
		}
	}
	else if (Board[nx][ny] == 1) RedPoint(piece, nx, ny);
	else WhitePoint(piece, nx, ny);

	if (!rangeCheck(nx, ny) && Chess[nx][ny].size() >= 4) return false;
	return true;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Board[i][j];
		}
	}

	int x, y, d;
	for (int i = 1; i <= K; i++) {
		cin >> x >> y >> d;
		Pos[i] = {i, x - 1, y - 1, 0, d};
		Chess[x - 1][y - 1].push_back(Pos[i]);
	}

	int turn = 0;
	while (turn++ <= 1000) {
		bool isContinue = true;
		for (int i = 1; i <= K; i++) {
			isContinue = movePiece(i);
			if (!isContinue) break;
		}
		if (!isContinue) break;
	}

	if (turn > 1000) cout << -1;
	else cout << turn;

	return 0;
}