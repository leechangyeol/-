#include <iostream>

using namespace std;

#define MAX 501

long double arr[MAX][MAX];
long double ans[MAX][MAX];
int n;


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	cin >> n;

	for (int i = 0; i < n; i++) 
	{
		ans[i][i] = 1;
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{

		int j = i-1;
		while (j + 1 < n && !arr[++j][i]);
			
		if (j == n - 1 && !arr[j][i])
		{
			cout << "no inverse";
			return 0;
		}
		for (int k = 0; k < n; k++) {
			swap(arr[j][k], arr[i][k]);
			swap(ans[j][k], ans[i][k]);
		}


		long double val = arr[i][i];

		for (int j = 0; j < n; j++) 
		{
			arr[i][j] /= val;
			ans[i][j] /= val;
		}
		for (int j = 0; j < n; j++)
		{
			if (j != i)
			{
				val = arr[j][i];
				for (int k = 0; k < n; k++)
				{
					if (k >= i) arr[j][k] -= arr[i][k] * val;
					ans[j][k] -= ans[i][k] * val;
				}
			}
		}
	}


	cout << fixed;
	cout.precision(8);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}

}
