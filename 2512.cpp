#include <iostream>
#define MAX 10000
using namespace std;

int city[MAX];
int n;
long long m;

int main(void)
{
	long long sum = 0;
	long long ans = 0;
	long long maxCity = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> city[i];
		if (maxCity < city[i])maxCity = city[i];
	}

	cin >> m;

	
	long long high, low, mid;
	high = maxCity;
	low = 1;
	ans = 0;
	while (low <= high)
	{
		mid = (high + low) / 2;
		sum = 0;
		for (int i = 0; i < n; i++)
		{
			if (mid > city[i])
				sum += city[i];
			else sum += mid;
		}

		if (sum <= m)
		{
			low = mid + 1;
			ans = mid;
		}
		else
		{
			high = mid - 1;
		}
	}

	cout << ans;
}
