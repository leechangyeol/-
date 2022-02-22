#include <iostream>
#define MAX 500

using namespace std;

int n, m;
int map[MAX][MAX];
int dp[MAX][MAX];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int dfs(int x, int y)
{
	if (x == m - 1 && y == n - 1)return 1;
	if (dp[y][x] != -1)return dp[y][x];

	dp[y][x] = 0;
	for (int i = 0; i < 4; i++) 
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (nx >= 0 && nx < m && ny >= 0 && ny < n)
		{
			if (map[ny][nx] < map[y][x]) dp[y][x] += dfs(nx,ny);
		}
	}

	return dp[y][x];
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;

	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			dp[i][j] = -1;
		}
	}

	dfs(0,0);
	cout << dfs(0, 0);

}
