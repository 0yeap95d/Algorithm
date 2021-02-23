#include <iostream>
#include <cstring>
#include <map>
#include <queue>
using namespace std;

string N, Ans;
int M, K;
queue<pair<string, int>> Que;
map<pair<string, int>, bool> Map;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> K;
	M = N.size();

	Que.push({ N, K });
	Map[{N, K}] = true;
	while (!Que.empty()) {
		string num = Que.front().first;
		int cnt = Que.front().second;
		Que.pop();

		if (cnt == 0) {
			if (atoi(Ans.c_str()) < atoi(num.c_str())) Ans = num;
			continue;
		}

		for (int i = 0; i < M - 1; i++) {
			for (int j = i + 1; j < M; j++) {
				string temp = num;
				temp[i] = num[j];
				temp[j] = num[i];
				if (Map[{temp, cnt - 1}] || temp[0] == '0') continue;
				Que.push({ temp, cnt - 1 });
				Map[{temp, cnt - 1}] = true;
			}
		}
	}

	if (Ans == "") Ans = "-1";
	cout << Ans;

	return 0;
}