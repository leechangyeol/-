#include <iostream>
#include <vector>
#include <queue>

#define MAX 1001
#define INF 999999999999

using namespace std;

long long dist[MAX];
int visited[MAX];
vector<pair<int, int>> edge[MAX];
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

int n, m;

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;

	for (int i = 0; i <= n; i++)
		dist[i] = INF;

	int a, b, c;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		edge[a].push_back({ b,c });
	}
	
	int start, dest;
	cin >> start >> dest;

	dist[start] = 0;
	pq.push({ 0 ,start});

	while (!pq.empty())
	{
		long long val = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (val > dist[cur])continue;

		for (int i = 0; i < edge[cur].size(); i++)
		{
			int next = edge[cur][i].first;
			long long nextVal = edge[cur][i].second;

			if (dist[next] > val + nextVal)
			{
				dist[next] = val + nextVal;
				pq.push({ dist[next], next });
				visited[next] = cur;
			}
		}
	}

	vector<int> ans;
	int trace = dest;
	while (trace)
	{
		ans.push_back(trace);
		trace = visited[trace];
	}

	cout << dist[dest] << "\n" << ans.size() << "\n";
	for (int i = ans.size() - 1; i >= 0; i--)
		cout << ans[i] << " ";
}
