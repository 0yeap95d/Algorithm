#include <iostream>
#include <queue>
#define SIZE 1001
using namespace std;

struct Emoticon {
	int time;
	int num;
	int clip;
};

int S, Ans;
queue<Emoticon> que;
bool visited[SIZE * 2][SIZE * 2];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> S;

	que.push({ 0, 1, 0 });
	while (!que.empty()) {
		Emoticon emo = que.front();
		que.pop();

		// 이모티콘 복사 (clip 덮어씌움)
		if (emo.num != 0 && !visited[emo.num][emo.num]) {
			
			visited[emo.num][emo.num] = true;
			que.push({ emo.time + 1, emo.num, emo.num });
		}

		// 이모티콘 붙여넣기 (clip이 존재해야함)
		if (emo.clip != 0 && emo.num + emo.clip < SIZE * 2 && !visited[emo.num + emo.clip][emo.clip]) {
			if (emo.num + emo.clip == S) {
				Ans = emo.time + 1;
				break;
			}
		
			visited[emo.num + emo.clip][emo.clip] = true;
			que.push({ emo.time + 1, emo.num + emo.clip, emo.clip });
		}

		// 이모티콘 삭제하기
		if (emo.num != 0 && !visited[emo.num - 1][emo.clip]) {
			if (emo.num - 1 == S) {
				Ans = emo.time + 1;
				break;
			}
			visited[emo.num - 1][emo.clip] = true;
			que.push({ emo.time + 1, emo.num - 1, emo.clip });
		}
	}

	cout << Ans;

	return 0;
}