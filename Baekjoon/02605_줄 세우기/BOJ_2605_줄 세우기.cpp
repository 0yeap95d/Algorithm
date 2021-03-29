#include <iostream>
#include <list>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N;
	cin >> N;

	int inp;
	list<int> student;
	student.push_back(0);
	cin >> inp;
	for (int i = 1; i < N; i++) {
		cin >> inp;
		auto iter = student.end();
		for (int j = 0; j < inp; j++) iter--;
		student.insert(iter, i);
	}

	for (int i : student) cout << i + 1<< " ";

	return 0;
}