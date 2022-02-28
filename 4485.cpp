#include <iostream>
#include <queue>

#define MAX 126
#define INF 99999999

int dis[MAX][MAX];
int map[MAX][MAX];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

using namespace std;

int n;
int main(void)
{
	int t = 1;
	while (1) 
	{
		cin >> n;
		if (n == 0)break;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> map[i][j];
				dis[i][j] = INF;
			}
		}

		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

		pq.push( {map[0][0],0 });

		dis[0][0] = map[0][0];

		while (!pq.empty())
		{
			int x = pq.top().second % n;
			int y = pq.top().second / n;
			int val = pq.top().first;
			pq.pop();

			for (int i = 0; i < 4; i++)
			{
				int nx = dx[i] + x;
				int ny = dy[i] + y;
				if (nx >= 0 && nx < n && ny >= 0 && ny < n)
				{
					if (dis[ny][nx] > val + map[ny][nx])
					{
						dis[ny][nx] = val + map[ny][nx];
						pq.push({ dis[ny][nx],ny * n + nx });
					}
				}
			}
		}

		cout << "Problem "<<t++<<": "<<dis[n - 1][n - 1]<<"\n";

	}
}
