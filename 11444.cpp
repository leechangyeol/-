#include <iostream>
#include <map>

using namespace std;
map <long long, long long> d;
const long long MOD = 1000000007LL;

long long fibo(long long n) {
	if (n <= 0)return 0;
	else if (n == 1)return 1;
	else if (n == 2)return 1;
	else if (d.count(n) > 0)return d[n];
	else {
		if (n % 2 == 0) {
			long long t1 = fibo(n / 2 - 1);
			long long t2 = fibo(n / 2);
			d[n] = (2LL * t1 + t2)*t2;
			d[n] %= MOD;
		}
		else {
			long long m = (n + 1) / 2;
			long long t1 = fibo(m);
			long long t2 = fibo(m - 1);
			d[n] = t1 * t1 + t2 * t2;
			d[n] %= MOD;
		}
	}
	return d[n];
}
int main(void) {
	long long n;
	cin >> n;
	cout << fibo(n);
}
