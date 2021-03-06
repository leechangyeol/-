#include <iostream>
#include <cstring>
using namespace std;
int n;
int const MAX = 1000001;
int dp[MAX];
int flag[MAX];
int main(void) {
	cin >> n;
	memset(dp, MAX, sizeof(dp));
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	flag[1] = 1;
	flag[2] = 2;
	flag[3] = 3;
	for (int i = 4; i <= n; i++) {
		if (i % 2 == 0) {
			if (dp[i] > dp[i / 2] + 1)
				dp[i] = dp[i/2] +1, flag[i] = 2;
		}
		if (i % 3 == 0) {
			if (dp[i] > dp[i / 3] + 1)
				dp[i] = dp[i / 3] + 1, flag[i] = 3;
		}
		if ((i - 1) % 2 == 0) {
			if (dp[i] > dp[(i - 1) / 2] + 2)
				dp[i] = dp[(i - 1) / 2] + 2, flag[i] = 4;
		}
		if ((i - 1) % 3 == 0) {
			if (dp[i] > dp[(i - 1) / 3] + 2)
				dp[i] = dp[(i - 1) / 3] + 2, flag[i] = 5;
		}
		if (dp[i] > dp[i - 1] + 1)
			dp[i] = dp[i - 1] + 1, flag[i] = 1;
	}
	cout << dp[n] << "\n";
	int ans = n;
	while (ans != 1) {
		if (flag[ans] == 4) {
			cout << ans-- << " ";
			cout << ans << " ";
			ans /= 2;
		}
		else if (flag[ans] == 5) {
			cout << ans-- << " ";
			cout << ans << " ";
			ans /= 3;
		}
		else if (flag[ans] == 1)
			cout << ans-- << " ";
		else cout << ans << " ", ans /= flag[ans];
	}
	cout << 1;
}
