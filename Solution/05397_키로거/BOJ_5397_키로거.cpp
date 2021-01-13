#include<iostream>
#include <cstring>
#include<list>
using namespace std;

int main() {

	int testCase;
	cin >> testCase;

	while (testCase--) {
		list<char> pwd;
		list<char>::iterator cursor = pwd.begin();
		string inp;
		cin >> inp;

		for (int i = 0; i < inp.size(); i++) {
			if (inp[i] == '<') { if (cursor != pwd.begin()) cursor--; }
			else if (inp[i] == '>') { if (cursor != pwd.end()) cursor++; }
			else if (inp[i] == '-') { if (cursor != pwd.begin()) cursor = pwd.erase(--cursor); }
			else pwd.insert(cursor, inp[i]);
		}

		for (auto ans : pwd) cout << ans;
		cout << "\n";
	}

	return 0;
}