#include <iostream>
#include <vector>
#include <queue>

#define NMAX 1001 
#define MMAX 10000
#define INF 99999999

using namespace std;
int dis[NMAX][NMAX];
vector<pair<int, int>> vec[NMAX];

int n, m, x;
int main(void)
{
	cin >> n >> m >> x;

	int a, b, val;
	for (int i = 0; i < m; i++) 
	{
		cin >> a >> b >> val;
		vec[a].push_back({ val,b });
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dis[i][j] = INF;

	for (int st = 1; st <= n; st++)
	{
		dis[st][st] = 0;

		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

		pq.push({ 0,st });

		while (!pq.empty())
		{
			int cost = pq.top().first;
			int cur = pq.top().second;
			pq.pop();

			for (int i = 0; i < vec[cur].size(); i++)
			{
				int nCost = vec[cur][i].first;
				int next = vec[cur][i].second;

				if (dis[st][next] > nCost + cost)
				{
					dis[st][next] = nCost + cost;
					pq.push({ dis[st][next], next });
				}
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i != x)
		{
			if (ans < dis[i][x] + dis[x][i]) ans = dis[i][x] + dis[x][i];
		}
	}

	cout << ans;

}
