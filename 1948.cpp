#include <iostream>
#include <vector>
#include <algorithm>
#define MAX  10001
using namespace std;

int n, m;
int start, dest;
vector<bool> visit;
vector< pair<int,pair<int,int>>> edge[MAX];
vector<int> mindist;
int ansDist, ansCount;
int dfs(int node) {
	if (node == dest)return 0;

	for (auto next : edge[node]) {
		if (!visit[next.second.first])
			mindist[node] = max(mindist[node], dfs(next.second.first) + next.second.second);
		else
			mindist[node] = max(mindist[node], mindist[next.second.first] + next.second.second);
	}

	visit[node] = true;

	return mindist[node];
}
void dfs2(int node, int dist) {

	if(dist + mindist[node] == ansDist)ansCount++;
	else return;
	for (int i = 0; i < edge[node].size();i++) {
		if (edge[node][i].first == 0) {
			dfs2(edge[node][i].second.first, dist + edge[node][i].second.second);
			edge[node][i].first = 1;
		}
	}

}
int main(void) {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	cin >> n >> m;

	visit = vector<bool>(n + 1, false);
	mindist = vector<int>(n + 1,0);

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edge[a].push_back({ 0,{b,c} });
	}

	cin >> start >> dest;

	ansDist = dfs(start);

	for(int i = 0;i<edge[start].size();i++)
		dfs2(edge[start][i].second.first, edge[start][i].second.second);

	cout << ansDist << "\n" << ansCount << "\n";

}
