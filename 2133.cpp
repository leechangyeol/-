#include <iostream>

using namespace std;

#define MAX 31

int dp[MAX];

int main(void)
{
	int n;
	
	dp[0] = 1;
	dp[1] = 0;
	dp[2] = 3;

	cin >> n;

	for (int i = 4; i <= n; i+=2) {
		dp[i] = dp[i - 2] * dp[2];
		for (int j = i-4; j >= 0; j -= 2) {
			dp[i] += dp[j] * 2;
		}
	}
	cout << dp[n];
}
