#include <iostream>

const int MOD = 1000000;
const int P = MOD / 10 * 15;

using namespace std;
long long n;
int fibo[P] = { 0,1 };
int main(void) {
	cin >> n;
	for (int i = 2; i < P; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
		fibo[i] %= MOD;
	}
	cout << fibo[n%P];
}
