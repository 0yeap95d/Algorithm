#include <iostream>
#include <stack>
typedef long long ll;
using namespace std;

int N;
ll Ans;
stack<int> Heights, Weights;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N;

	int inp;
	for (int i = 0; i < N; i++) {
		cin >> inp;

		if (Heights.empty()) {
			Heights.push(inp);
			Weights.push(1);
		}

		else if (Heights.top() > inp) {
			Ans = Ans + 1;
			Heights.push(inp);
			Weights.push(1);
		}

		else if (Heights.top() == inp) {
			int weight = Weights.top();
			Ans = Ans + weight;
			Heights.pop();
			Weights.pop();

			if (!Heights.empty()) Ans = Ans + 1;
			Heights.push(inp);
			Weights.push(weight + 1);
		}

		else {
			int weight = 0;
			while (!Heights.empty() && Heights.top() <= inp) {
				Ans = Ans + Weights.top();
				if (Heights.top() == inp) weight = Weights.top();
				Heights.pop();
				Weights.pop();
			}
			if (!Heights.empty()) Ans = Ans + 1;
			Heights.push(inp);
			Weights.push(weight + 1);
		}
	}

	cout << Ans;

	return 0;
}