#include <iostream>
#include <string>
#define MAX 4000
using namespace std;

int dp[MAX][MAX];
int main(void)
{
	string a, b;
	cin >> a >> b;

	int ans = 0;
	
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < b.size(); j++)
		{
			if (a[i] == b[j]) 
			{
				if (j == 0 || i == 0)
					dp[i][j] = 1;
				else
					dp[i][j] = dp[i - 1][j - 1] + 1;

				if (ans < dp[i][j]) ans = dp[i][j];
			}
		}
	}

	cout << ans;
}
