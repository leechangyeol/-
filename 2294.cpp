#include <iostream>

using namespace std;

#define KMAX 100001
#define NMAX 101

int dp[KMAX];
int narray[NMAX];

int n, k;

int main(void)
{
	cin >> n >> k;

	for (int i = 0; i < KMAX; i++)
		dp[i] = KMAX;

	for (int i = 0; i < n; i++) {
		cin >> narray[i];
		dp[narray[i]] = 1;

		for (int j = narray[i]; j <= k; j++)
			if (dp[j] > dp[j - narray[i]] + 1)dp[j] = dp[j - narray[i]] + 1;
	}
	
	if (dp[k] == KMAX)
		cout << "-1";
	else 
		cout << dp[k];

	return 0;
}
