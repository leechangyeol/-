#include <iostream>
#include <deque>

using namespace std;

int n, m;
deque<int> d;
int main(void)
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		d.push_back(i);
	}

	int ans = 0;

	for (int i = 0; i < m; i++)
	{
		int num, index;
		cin >> num;

		for (int j = 0; j < d.size(); j++)
		{
			if (num == d[j])
			{
				index = j;
				break;
			}
		}

		if (index < d.size() - index)
		{
			while(d.front() != num)
			{
				d.push_back(d.front());
				d.pop_front();
				ans++;
			}
			d.pop_front();
		}
		else
		{
			while(d.back() != num)
			{
				d.push_front(d.back());
				d.pop_back();
				ans++;
			}
			ans++;
			d.pop_back();
		}
	}

	cout << ans;
}
