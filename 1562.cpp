#include <iostream>
using namespace std;
typedef long long ll;
int n;
const int MAX = 101;
const ll MOD = 1000000000;
ll dp[MAX][10][(1<<10)];
ll ans;
int dfs(int num, int bit, int cnt) {
	if (dp[cnt][num][bit]) return dp[cnt][num][bit];
	if (cnt == n) {
		if (bit == (1 << 10) - 1) return 1;
		else return 0;
	}
	ll ret = 0;
	if (num + 1 < 10)
		ret += dfs(num + 1, (bit | 1 << (num + 1)), cnt + 1);
	if (num - 1 >= 0)
		ret += dfs(num - 1, (bit | 1 << (num - 1)), cnt + 1);
	
	return dp[cnt][num][bit] = ret %= MOD;

}
int main(void) {
	cin >> n;
	int bitmask = 0;
	int test = 0;
	for (int i = 1; i < 10; i++) {
		ans += dfs(i, 1 << i, 1);
		ans %= MOD;
	}
	cout << ans;
}
