#include <iostream>

using namespace std;

#define MAX 101

long long dp[MAX];
int main(void)
{

	dp[0] = dp[1] = dp[2] = 1;
	dp[3] = dp[4] = 2;
	for (int i = 5; i < MAX; i++)
		dp[i] = dp[i - 1] + dp[i - 5];
	
	int n;
	cin >> n;

	int p;
	for (int i = 0; i < n; i++)
	{
		cin >> p;
		cout << dp[p-1] << "\n";
	}
}
