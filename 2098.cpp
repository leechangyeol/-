#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 16;
const int BIT_MAX = 1 << MAX;
const int INF = 987654321;
int n;
int map[MAX][MAX];
int dp[MAX][BIT_MAX];
int ans_bit;
int dfs(int node, int bit) {
	if (dp[node][bit] != 0)return dp[node][bit];

	if (bit == ans_bit) {
		if (map[node][0] == 0)return INF;
		else return map[node][0];
	}

	dp[node][bit] = INF;
	for (int i = 0; i < n; i++) {
		if (map[node][i] == 0)continue;
		if ((bit & (1 << i)) == (1 << i))continue;
		dp[node][bit] = min(dp[node][bit],map[node][i] + dfs(i, bit | (1 << i)));
	}
	return dp[node][bit];
}
int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	ans_bit = (1 << n) - 1;
	cout << dfs(0, 1);
}
