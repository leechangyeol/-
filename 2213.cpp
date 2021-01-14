#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 10001;
vector<int> edge[MAX];
int value[MAX];
int dp[MAX][2];
bool visit[MAX];
bool visit2[MAX];
int n;
vector<int> ans;
void dfs(int node) {
	visit[node] = true;

	dp[node][0] = 0;
	dp[node][1] = value[node];
	for (auto next : edge[node]) {
		if (visit[next])continue;
		dfs(next);
		dp[node][0] += max(dp[next][1], dp[next][0]);
		dp[node][1] += dp[next][0];
	}
}
void trace(int node,bool print) {
	visit2[node] = true;
	if (!print && dp[node][1] > dp[node][0]) {
		ans.push_back(node);
		for (auto next : edge[node]) {
			if (visit2[next])continue;
			trace(next, true);
		}
	}
	else {
		for (auto next : edge[node]) {
			if (visit2[next])continue;
			trace(next, false);
		}
	}
}
int main(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) {cin >> value[i];}
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	dfs(1);
	trace(1, false);
	sort(ans.begin(), ans.end());
	cout << max(dp[1][0], dp[1][1])<<"\n";
	for (auto next : ans)
		cout << next << " ";
}
