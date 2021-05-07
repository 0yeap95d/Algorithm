#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

string medianExp, Answer;
stack<char> oper;

void getAllOper() {
	while (!oper.empty() && oper.top() != '(') {
		Answer += oper.top();
		oper.pop();
	}
}

void getSubOper() {
	while (!oper.empty() && oper.top() != '(' && (oper.top() == '*' || oper.top() == '/')) {
		Answer += oper.top();
		oper.pop();
	}
}

void getBracketOper() {
	while (!oper.empty() && oper.top() != '(') {
		Answer += oper.top();
		oper.pop();
	}
	oper.pop();
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> medianExp;
	for (int i = 0; i < medianExp.size(); i++) {
		if (medianExp[i] == '+' || medianExp[i] == '-') {
			getAllOper();
			oper.push(medianExp[i]);
		}
		else if (medianExp[i] == '*' || medianExp[i] == '/') {
			getSubOper();
			oper.push(medianExp[i]);
		}
		else if (medianExp[i] == '(') {
			oper.push(medianExp[i]);
		}
		else if (medianExp[i] == ')') {
			getBracketOper();
		}
		else Answer += medianExp[i];
	}

	getAllOper();
	cout << Answer;

	return 0;
}