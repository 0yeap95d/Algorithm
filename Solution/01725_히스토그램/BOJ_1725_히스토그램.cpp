#include <iostream>
#include <stack>
#include <algorithm>
#define SIZE 100002
typedef long long ll;
using namespace std;

int N;
int Height[SIZE];
stack<ll> Histo;
ll Ans;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) cin >> Height[i];

	for (int i = 0; i <= N + 1; i++) {
		while (!Histo.empty() && Height[Histo.top()] > Height[i]) {
			ll height = Height[Histo.top()]; 
			Histo.pop();
			ll width = i - Histo.top() - 1;
			Ans = max(Ans, width * height);
		}
		Histo.push(i);
	}

	cout << Ans;
	return 0;
}