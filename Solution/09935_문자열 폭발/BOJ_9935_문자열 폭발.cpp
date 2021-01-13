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

			// ���� ���ڿ� ���̸�ŭ ��������
			for (int i = 0; i < boom.size(); i++) {
				
				// ���ڿ��� ��ġ���� ���� �� �����Ƿ� temp ���ÿ� �ӽ� ����
				if (!st.empty() && st.top() == boom[i]) {
					temp.push(st.top());
					st.pop();
				}

				// ���ڿ��� ��ġ���� ������ �ٽ� �ֿ����
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

	// ���� ���
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