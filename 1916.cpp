#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 1001
#define INF 99999999

vector<pair<int, int>> vec[MAX];
priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int dis[MAX];
int n, m;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	int s, d, v;
	int a, b;

	for (int i = 0; i <= n; i++)
	{
		dis[i] = INF;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> s >> d >> v;
		vec[s].push_back({ v,d });
	}

	cin >> a >> b;
	
	dis[a] = 0;

	
	int val;
	int start;
	pq.push({ 0, a });

	while (!pq.empty())
	{
		val = pq.top().first;
		start = pq.top().second;
		pq.pop();

		if (dis[start] < val)continue;
		for (int i = 0; i < vec[start].size(); i++)
		{
			int dest = vec[start][i].second;
			int dval = vec[start][i].first;

			if (dis[dest] > val + dval)
			{
				dis[dest] = val + dval;
				pq.push({ dis[dest],dest });
			}
		}
	}

	cout << dis[b];
}
