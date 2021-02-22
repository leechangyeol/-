#include <iostream>
using namespace std;
int m, n;
const int MAX = 10001;
const int INF = 98765432;
int dp[MAX];
int memory[101];
int cost[101];
int main(void) { 
	cin >> n >> m;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> memory[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> cost[i];
		sum += cost[i];
	}

	for (int i = 0; i < n; i++){
		for (int j = sum; j >= cost[i]; j--) {
			dp[j] = max(dp[j], dp[j - cost[i]] + memory[i]);
		}
	}
	int ans;
	for (ans = 0; ans < sum, dp[ans] < m; ans++) {}
	cout << ans;
}
