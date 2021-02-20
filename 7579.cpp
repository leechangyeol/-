
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
const int MAX = 100001;
const int INF = 987654321;
int dp[101][MAX];
int cost[101];
int memory[101];
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> memory[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> cost[i];
	}
	dp[0][cost[0]] = memory[0];
	int ans = INF;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < MAX; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j >= cost[i]) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[i]] + memory[i]);
			}
			if (dp[i][j] >= m) { 
				ans = min(ans, j);
			}
		}
	}
	cout << ans <<"\n";
	return 0;
}
