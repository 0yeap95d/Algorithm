#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	string word, boom;
	cin >> word >> boom;
	reverse(boom.begin(), boom.end());

	stack<char> st;

	for (char w : word) {
		st.push(w);

		if (st.top() == boom[0]) {
			stack<char> temp;

			// 폭발 문자열 길이만큼 꺼내보기
			for (int i = 0; i < boom.size(); i++) {
				
				// 문자열이 일치하지 않을 수 있으므로 temp 스택에 임시 저장
				if (!st.empty() && st.top() == boom[i]) {
					temp.push(st.top());
					st.pop();
				}

				// 문자열이 일치하지 않으면 다시 주워담기
				else {
					while(!temp.empty()) {
						st.push(temp.top());
						temp.pop();
					}
					break;
				}
			}
		}

	}

	// 정답 출력
	if (st.empty()) cout << "FRULA";
	else {
		string out;
		while (!st.empty()) {
			out += st.top();
			st.pop();
		}
		reverse(out.begin(), out.end());
		cout << out;
	}

	return 0;
}