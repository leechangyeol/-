#include <iostream>
#include <vector>
#include <queue>

#define INF 1000000001
#define MAX 5001
#define ll long long


using namespace std;

vector<pair<ll, ll>> edge[MAX];
ll val[MAX][MAX];
bool visited[MAX][MAX];

void bfs(int n)
{
	queue < pair <ll, ll >> q;

	q.push({ n, INF });

	while (!q.empty())
	{
		ll cur =  q.front().first;
		ll curVal = q.front().second;
		q.pop();

		if (val[n][cur] > curVal) val[n][cur] = curVal;
		visited[n][cur] = true;

		for (int i = 0; i < edge[cur].size(); i++)
		{
			ll next = edge[cur][i].first;
			ll nextVal = edge[cur][i].second;

			if (!visited[n][next])
			{
				if (curVal > nextVal)
					q.push({ next,nextVal });
				else q.push({ next, curVal });
			}
		}
	}
}

int main(void)
{
	int n, q;

	cin >> n >> q;

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			val[i][j] = INF;

	for (int i = 0; i < n-1; i++)
	{
		int a, b;
		ll val;
		cin >> a >> b >> val;
		edge[a].push_back({ b,val });
		edge[b].push_back({ a,val });
	}

	for (int i = 1; i <= n; i++)
	{
		bfs(i);
	}


	for (int i = 0; i < q; i++)
	{
		ll a, b;
		int ans = 0;

		cin >> a >> b;

		for (int j = 1; j <= n; j++)
		{
			if (a <= val[b][j] && val[b][j] != INF)
				ans++;
		}
		cout << ans << "\n";
	}


}
