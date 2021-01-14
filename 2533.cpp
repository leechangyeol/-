#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 1000001;
vector<int> edge[MAX];
int dp[MAX][2];
bool visit[MAX];
int n;
void dfs(int node) {
	visit[node] = true;

	dp[node][0] = 0;
	dp[node][1] = 1;
	for (auto next : edge[node]) {
		if (visit[next])continue;
		dfs(next);
		dp[node][0] += dp[next][1];
		dp[node][1] += min(dp[next][0], dp[next][1]);
	}
}
int main(void) {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	dfs(1);
	cout << min(dp[1][0], dp[1][1]);
}
