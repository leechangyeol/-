#include <iostream>
#include <vector>
#include <queue>

#define MAX 801
#define INF 210000000
using namespace std;

int dis[MAX][3];
bool visit[MAX][3];

vector<pair<int, int>> edge[MAX];

void sol(int start,int v)
{
	priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> pq;
	dis[start][v] = 0;
	pq.push({ 0,start});

	while (!pq.empty())
	{
		int cur = pq.top().second;
		pq.pop();

		for (int i = 0; i< edge[cur].size(); i++) {
			int val = edge[cur][i].first;
			int next = edge[cur][i].second;
			if (dis[next][v] > dis[cur][v] + val) {
				dis[next][v] = dis[cur][v] + val;
				pq.push({ dis[next][v],next });
			}
		}
	}

}

int main(void) 
{
	int n, e;
	cin >> n >> e;

	int s, d, v;
	for (int i = 0; i < e; i++) {
		cin >> s >> d >> v;
		edge[s].push_back({ v,d });
		edge[d].push_back({ v,s });
	}
	
	int v1, v2;
	cin >> v1 >> v2;

	for (int i = 0; i <= n; i++) {
		dis[i][0] = dis[i][1] = dis[i][2] = INF;
	}

	sol(1, 0);
	sol(v1, 1);
	sol(v2, 2);

	int ans = INF;

	if (dis[v1][0] != INF && dis[v2][1] != INF && dis[n][2] != INF)
		ans = dis[v1][0] + dis[v2][1] + dis[n][2];

	if (dis[v2][0] != INF && dis[v1][2] != INF && dis[n][1] != INF)
		if (ans > dis[v2][0] + dis[v1][2] + dis[n][1])
			ans = dis[v2][0] + dis[v1][2] + dis[n][1];
	
	if (ans == INF) cout << "-1";
	else cout << ans;
}
