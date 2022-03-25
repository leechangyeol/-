#include <iostream>

using namespace std;

int main(void)
{
	int t, n, m;
	cin >> t;

	while (t--)
	{
		cin >> n >> m;

		long long ans = 1;
		for (int i = 0; i < n; i++)
		{
			ans *= (m - i);
			ans /= (i + 1);
		}

		cout << ans << "\n";
	}
}
