#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;

typedef long long ll;

ll N;

vector<ll> mulVec(vector<ll> a, vector<ll> b) {
	vector<ll> res;
	res.push_back((a[0] * b[0] + a[1] * b[1]) % MOD);
	res.push_back((a[0] * b[1] + a[1] * b[2]) % MOD);
	res.push_back((a[1] * b[1] + a[2] * b[2]) % MOD);
	return res;
}

vector<ll> fibo(ll n) {
	if (n == 1) return { 0, 1, 1 };
	if (n % 2) return mulVec(fibo(n - 1), { 0, 1, 1 });
	else {
		vector<ll> vec = fibo(n / 2);
		return mulVec(vec, vec);
	}
}

int main() {

	cin >> N;
	vector<ll> ans = fibo(N);
	cout << ans[1];

	return 0;
}