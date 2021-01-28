#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 501;
int dp[MAX][MAX];
int n;
int main(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++)
			cin >> dp[i][j];
	}

	for (int i = 2; i <= n; i++){
		dp[i][1] += dp[i - 1][1];
		dp[i][i] += dp[i - 1][i - 1];
		for (int j = 2; j <= i - 1; j++) {
			dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);
		}
	}
	sort(dp[n] + 1, dp[n] + n + 1, less<int>());
	cout << dp[n][n];
}
