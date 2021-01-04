#include <iostream>
#include <vector>
#include <algorithm>
#define INT_MAXX 987654321
#define MAX  10001
using namespace std;

int n, m;
int start, dest;
bool visit[MAX];
vector< pair<int,pair<int,int>>> edge[MAX];
vector<int> mindist;
int ansDist, ansCount;
int dfs(int node) {
	if (node == dest)return 0;

	for (auto next : edge[node]) {
			mindist[node] = max(mindist[node], dfs(next.second.first) + next.second.second);
	}
	return mindist[node];
}
void dfs2(int node, int dist) {
	

	for (int i = 0; i < edge[node].size();i++) {
		if (edge[node][i].first == 0) {
			if (ansDist == mindist[edge[node][i].second.first] + dist + edge[node][i].second.second) {
				ansCount++;
			}
			dfs2(edge[node][i].second.first, dist + edge[node][i].second.second);
			edge[node][i].first = 1;
		}
	}

}
int main(void) {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	cin >> n >> m;

	mindist = vector<int>(n + 1,0);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edge[a].push_back({ 0,{b,c} });
	}

	cin >> start >> dest;

	ansDist = dfs(start);
	dfs2(start,0);
	cout << ansDist << " " << ansCount << "\n";

}
