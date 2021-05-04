#include <iostream>
#include <unordered_map>
using namespace std;

int N, M;
unordered_map<string, string> table;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> M;

	string address, password;
	for (int i = 0; i < N; i++) {
		cin >> address >> password;
		table[address] = password;
	}

	for (int i = 0; i < M; i++) {
		cin >> address;
		cout << table[address] << "\n";
	}

	return 0;
}