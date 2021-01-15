#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> matrix;
const ll MOD = 1000000007; 
matrix operator *(const matrix& a, const matrix& b) {
	ll size = a.size();
	matrix res(size, vector<ll>(size, 0));
	for (ll i = 0; i < size; i++) {
		for (ll j = 0; j < size; j++) {
			for (ll k = 0; k < size; k++) {
				res[i][j] += a[i][k] * b[k][j];
				res[i][j] %= MOD;
			}
		}
	}
	return res;
}
matrix _pow(matrix a, ll n) {
	ll size = a.size();
	matrix res(size, vector<ll>(size));
	for (ll i = 0; i < size; i++)
			res[i][i] = 1;
	while (n > 0) {
		if (n % 2 == 1)res = res * a;
		n /= 2;
		a = a * a;
	}
	return res;
}
int main(void) {
	ll n, k;
	cin >> k >> n;

	matrix trial(k+2, vector<ll>(k+2, 0));
	for (int i = 0; i < k+2; i++) {
		for (int j = 0; j <= i; j++) {
			trial[i][j] = 1;
		}
	}
	
	matrix ans_matrix;
	ans_matrix = _pow(trial, n - 1);

	ll sum = 0;
	for (auto value : ans_matrix[k + 1]) {
		sum += value;
		sum %= MOD;
	}
	cout << sum;
}
