#include <iostream>
#include <vector>
#include <cstring>
typedef long long ll;
using namespace std;
const int MAX = 51;
const ll MOD = 1000000007;
bool visit[MAX];
vector<int> edge[MAX];
vector<int> sub[MAX];
ll dp[MAX][MAX][MAX];
int n, k;
void dfs(int here,int parent) {
	visit[here] = true;
	for (auto next : edge[here]) {
		if (visit[next])continue;
		sub[here].push_back(next);
		dfs(next, here);
	}
}
ll dpfun(int root, int idx, int people) {
	if (people == 0)return 1;
	if (idx == sub[root].size()) {
		if (people == 1)return 1; 
		else return 0; 
	}
	ll& ret = dp[root][idx][people];
	if (ret != -1)return ret;
	ret = 0;
	for (int i = 0; i < people; i++) {
		ret += dpfun(sub[root][idx], 0, i) * dpfun(root, idx + 1, people - i);
		ret %= MOD;
	}
	return ret;
}

int main(void) {
	cin >> n >> k;
	int a, b;
	for (int i = 0; i < n-1; i++) {
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	memset(dp, -1, sizeof(dp));
	dfs(1,-1);
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += dpfun(i, 0, k);
		ans %= MOD;
	}
	cout << ans;
}
