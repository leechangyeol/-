#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> matrix;
const int MOD = 1000;
matrix operator *(const matrix& a, const matrix& b) {
	ll size = a.size();
	matrix res(size, vector<ll>(size, 0));
	for (ll i = 0; i < size; i++) {
		for (ll j = 0; j < size; j++) {
			for (ll k = 0; k < size; k++) {
				res[i][j] += a[i][k] * b[k][j];
			}
			res[i][j] %= MOD;
		}
	}
	return res;
}
matrix _pow(matrix a, ll n) {
	ll size = a.size();
	matrix res(size, vector<ll>(size));
	for (int i = 0; i < size; i++)
			res[i][i] = 1;
	while (n > 0) {
		if (n % 2 == 1)res = res * a;
		n /= 2;
		a = a * a;
	}
	return res;
}
int main(void) {
	ll n, b;
	cin >> n >> b;
	matrix a, ans;
	a = matrix(n, vector<ll>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	}
	ans = _pow(a, b);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << ans[i][j] << " ";
		cout << "\n";
	}
}
