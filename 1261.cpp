#include <iostream>
#include <queue>
#define MAX 101
#define INF 99999999

using namespace std;

int map[MAX][MAX];
int dis[MAX][MAX];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int main(void)
{
	int n, m;

	cin >> n >> m;


	string temp;
	for (int i = 0; i < m; i++)
	{
		cin >> temp;
		for (int j = 0; j < n; j++)
		{
			map[i][j] = temp[j] - '0';
			dis[i][j] = INF;
		}
	}

	queue<pair<int, int>> qu;

	qu.push({ 0,0 });

	dis[0][0] = 0;

	while (!qu.empty())
	{
		int x = qu.front().first;
		int y = qu.front().second;
		qu.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m)
			{
				if (dis[ny][nx] > dis[y][x] + map[ny][nx])
				{
					dis[ny][nx] = dis[y][x] + map[ny][nx];
					qu.push({ nx, ny });
				}
			}
		}

	}

	cout << dis[m - 1][n - 1];
}
