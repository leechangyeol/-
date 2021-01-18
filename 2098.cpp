#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 16;
const int INF = 987654321;
int map[MAX][MAX];
int dp[MAX][(1 << MAX)];
int n, ans_bit;
int dfs(int node, int bit) {
	if (bit == ans_bit) 
	{
		if (map[node][0] == 0)return INF;
		else return map[node][0];
	}
	if (dp[node][bit] != -1)return dp[node][bit];
	dp[node][bit] = INF;
	for (int i = 0; i < n; i++) {
		if (map[node][i] == 0) continue;
		if (bit & (1 << i))continue;
		dp[node][bit] = min(dp[node][bit],map[node][i] + dfs(i, bit | (1 << i)));
	}
	return dp[node][bit];
}
int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	}
	memset(dp, -1, sizeof(dp));
	ans_bit = (1 << n) - 1;
	cout << dfs(0, 1);
}
