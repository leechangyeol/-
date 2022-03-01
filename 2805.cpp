#include <iostream>
#define MAX 1000000

using namespace std;

int n;
long long m;

long long tree[MAX];
int main(void)
{
	cin >> n >> m;

	long long max = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> tree[i];
		if (max < tree[i]) max = tree[i];
	}

	long long low, high, mid;
	low = 0;
	high = max;
	long long total;
	long long ans = 0;
	while (low <= high)
	{
		mid = (high + low) / 2;
		total = 0;
		for (int i = 0; i < n; i++)
		{
			if(tree[i]- mid >= 0)
				total += tree[i] - mid;
		}
		if (total >= m)
		{
			low = mid + 1;
			if (ans < mid) ans = mid;
		}
		else
		{
			high = mid - 1;
		}
	}

	cout << ans;
}
