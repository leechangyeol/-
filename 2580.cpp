#include <iostream>
#define MAX 9

using namespace std;

int map[MAX][MAX];

bool blockCheck(int x, int y, int val)
{
	int nx = (x / 3) * 3;
	int ny = (y / 3) * 3;
	
	bool check[10] = {0,};
	
	for (int i = ny; i < ny + 3; i++)
	{
		for (int j = nx; j < nx + 3; j++)
		{
			if (!check[map[i][j]])check[map[i][j]] = true;
		}
	}
	if (!check[val]) {
		return true;
	}
	else return false;
}

bool colCheck(int x, int y,int val)
{
	bool check[10] = { 0, };
	
	for (int i = 0; i < MAX; i++)
	{
		if (!check[map[y][i]])
			check[map[y][i]] = true;
	}

	if (!check[val]) {
		return true;
	}
	else return false;
}

bool rowCheck(int x, int y,int val)
{
	bool check[10] = { 0, };

	for (int i = 0; i < MAX; i++)
	{
		if (!check[map[i][x]])
			check[map[i][x]] = true;
	}

	if (!check[val]) {
		return true;
	}
	else return false;
}


void dfs(int n)
{
	if (n == MAX*MAX)
	{
		for (int i = 0; i < MAX; i++)
		{
			for (int j = 0; j < MAX; j++)
			{
				cout << map[i][j] << " ";
			}
			cout << "\n";
		}
		exit(0);
	}
	else 
	{
		if (map[n / 9][n % 9]) dfs(n + 1);
		else
		{
			for (int i = 1; i < 10; i++)
			{
				if (blockCheck(n % 9, n / 9, i) && colCheck(n % 9, n / 9, i) && rowCheck(n % 9, n / 9, i))
				{
					map[n / 9][n % 9] = i;

					dfs(n + 1);
				}
			}
			map[n / 9][n % 9] = 0;
		}
	}
}

int main(void)
{
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			cin >> map[i][j];
		}
	}

	dfs(0);
}
