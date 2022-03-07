#include <iostream>
#include <algorithm>

#define MAX 5001
using namespace std;
int dp[MAX][MAX];
string a;
int main(void)
{
	cin >> a;
	cin >> a;

	string b = "";

	for (int i = 0; i < a.size(); i++)
	{
		b = a[i] + b;
	}

	for (int i = 1; i <= a.size(); i++)
	{
		for (int j = 1; j <= b.size(); j++)
		{
			dp[i][j] = max({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] + (a[i - 1] == b[j - 1]) });
		}
	}

	cout << a.size() - dp[a.size()][b.size()];
}
