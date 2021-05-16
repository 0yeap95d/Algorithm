#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int TC;
	cin >> TC;

	string inp;
	getline(cin, inp);

	while (TC--) {
		getline(cin, inp);

		stack<char> st;
		for (char ch : inp) {
			if (ch == ' ') {
				while (!st.empty()) {
					cout << st.top();
					st.pop();
				}
				cout << ch;
			}
			else st.push(ch);
		}

		while (!st.empty()) {
			cout << st.top();
			st.pop();
		}
		cout << '\n';
	}

	return 0;
}