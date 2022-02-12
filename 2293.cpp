#include <iostream>

using namespace std;

#define KMAX 10001
#define NMAX 101

int dp[KMAX];
int narray[NMAX];

int n, k;

int main(void)
{
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> narray[i];
	}
	dp[0] = 1;
	for (int i = 0; i < n;i++) {
		for (int j = narray[i]; j <= k; j++) {
			dp[j] = dp[j] + dp[j - narray[i]];
		}
	}
	cout << dp[k];
}
