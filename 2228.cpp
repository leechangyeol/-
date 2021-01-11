#include <iostream>
#include <algorithm>
using namespace std;
int n1, m1;
int dp[102][52];
bool visit[102][52];
int sum[102];
int solve(int n, int m) {
	if (m == 0)return 0;
	else if (n < 2 * m - 1)return -987654321;
	else if (visit[n][m])return dp[n][m];
	
	visit[n][m] = true;
	dp[n][m] = solve(n - 1, m);

	for (int i = n; i > 0; i--) {
		dp[n][m] = max(dp[n][m], sum[n] - sum[i - 1] + solve(i - 2, m - 1));
	}
	return dp[n][m];
}
int main(void) {
	cin >> n1 >> m1;
	for (int i = 1; i <= n1; i++) {
		int a;
		cin >> a;
		sum[i] = sum[i - 1] + a;
	}
	cout << solve(n1, m1);
}
