#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int n, t;
const int MAX = 100001;
ll dp[MAX][2];
int main(void) {
	cin >> t;
	for (int test = 0; test < t; test++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> dp[i][0];
		}
		for (int i = 0; i < n; i++) {
			cin >> dp[i][1];
		}
		if (n >= 2) {
			dp[1][0] += dp[0][1]; dp[1][1] += dp[0][0];
		}

		for (int i = 2; i < n; i++) {
			dp[i][0] += max(dp[i - 2][1], dp[i - 1][1]);
			dp[i][1] += max(dp[i - 2][0], dp[i - 1][0]);
		}
		cout << max({ dp[n - 1][0], dp[n - 1][1],dp[n - 2][0],dp[n - 2][1] })<<"\n";
	}
}
