#include <iostream>
#include <numeric>
using namespace std;
typedef long long ll;
const int MAX = 10001;
const ll MOD = 1000000009;
ll dp[MAX][4];
int n, t;
int main(void) {
	cin >> t;
	dp[1][1] = 1;
	dp[2][1] = 1;
	dp[2][2] = 1;
	dp[3][1] = 1;
	dp[3][2] = 1;
	dp[3][3] = 1;
	for (int i = 4; i < MAX; i++) {
		dp[i][1] = dp[i - 1][1];
		dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
		dp[i][3] = dp[i - 3][3] + dp[i - 3][2] + dp[i - 3][1];
	}
	for (int test = 0; test < t; test++) {
		cin >> n;
		cout << accumulate(dp[n], dp[n] + 4, 0ll) << "\n";
	}
}
