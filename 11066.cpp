#include <iostream>
#include <algorithm>
#define MAX 501
using namespace std;

int dp[MAX][MAX];
int cost[MAX];
int sum[MAX];

int main(void) { 
	cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int time = 0; time < t; time++) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> cost[i];
			sum[i] = sum[i - 1] + cost[i];
		}

		for (int i = 1; i < n; i++) {
			for (int tx = 1; tx + i <= n; tx++) {
				int ty = tx + i;
				dp[tx][ty] = INT_MAX;
				for (int mid = tx; mid < ty; mid++)
					dp[tx][ty] = min(dp[tx][ty], dp[tx][mid] + dp[mid + 1][ty] + sum[ty] - sum[tx - 1]);
			}
		}

		cout << dp[1][n] << "\n";
	}
}
