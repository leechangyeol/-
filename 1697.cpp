#include <iostream>
#include <algorithm>
using namespace std;
int n, k;
const int MAX = 100001;
int dp[MAX];
int main(void) {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 0; i <= n; i++) {
		dp[i] = n - i;
	}
	for (int i = n+1; i <= k; i++) {
		if (i > n)dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0)dp[i] = min(dp[i], dp[i / 2] + 1);
		else { 
			if ((i - 1) / 2 >= 0)
				dp[i] = min(dp[i], dp[(i - 1) / 2] + 2); 
			dp[i] = min(dp[i], dp[(i + 1) / 2] + 2);
		}
		
		dp[i] = min(dp[i], dp[i - 1] + 1);
	}
	cout << dp[k];
}
