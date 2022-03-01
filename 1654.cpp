#include <iostream>
#define MAX 10000

using namespace std;

int k, n;
int line[MAX];
int main(void)
{
	cin >> k >> n;

	long high = 0;
	long low = 1;
	long mid;
	int cnt;

	for (int i = 0; i < k; i++) 
	{
		cin >> line[i];
		if (high < line[i]) high = line[i];
	}

	int max = 0;

	while (low <= high)
	{
		mid = (low + high) / 2;
		cnt = 0;
		for (int i = 0; i < k; i++)
			cnt += line[i] / mid;

		if (cnt >= n)
		{
			low = mid + 1;
			if (max < mid)max = mid;
		}
		else
		{
			high = mid - 1;
		}
	}
	
	cout << max;
}
