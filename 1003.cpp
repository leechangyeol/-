#include <iostream>
using namespace std;
const int MAX = 41;
int dp[MAX];
int main(void) {
	dp[0] = dp[1] = 1;
	for (int i = 2; i < MAX; i++)
		dp[i] = dp[i - 1] + dp[i - 2];

	int t;
	cin >> t;
	int n;
	while (t--) {
		cin >> n;
		if (n == 0)cout << dp[0] << " " << 0 << "\n";
		else cout << dp[n - 2] << " " << dp[n - 1]<<"\n";
	}
}
