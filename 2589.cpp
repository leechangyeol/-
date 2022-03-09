#include <iostream>
#include <queue>

#define MAX 51
#define INF 99999999

using namespace std;

int map[MAX][MAX];
int dis[MAX][MAX];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int n, m;
int ans;

void bfs(int x, int y)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			dis[i][j] = INF;
		}
	}

	int max = 0;
	dis[y][x] = 1;

	queue<pair<int, int>> qu;
	
	qu.push({ x, y });

	while (!qu.empty())
	{
		int curx = qu.front().first;
		int cury = qu.front().second;
		qu.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = curx + dx[i];
			int ny = cury + dy[i];

			if (nx >= 0 && nx < m && ny >= 0 && ny < n && map[ny][nx] == 2 && dis[ny][nx] == INF)
			{
				if (dis[ny][nx] > dis[cury][curx] + 1) 
				{
					dis[ny][nx] = dis[cury][curx] + 1;
					if (dis[ny][nx] > ans) ans = dis[ny][nx];
					qu.push({ nx, ny });
				}
			}
		}
	}

	return;
}
int main(void)
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;
		for (int j = 0; j < m; j++)
		{
			if (temp[j] == 'W')
				map[i][j] = 1;
			else map[i][j] = 2;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			if (map[i][j] == 2)
				bfs(j, i);
	}

	cout << ans-1;
}
