#include <iostream>

using namespace std;

int main(void)
{
	int t;
	cin >> t;

	while (t--)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		int n;
		cin >> n;
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			int cx, cy, r, d1, d2;
			cin >> cx >> cy >> r;
			bool d1bool, d2bool;

			d1 = (cx - x1)* (cx - x1) + (cy - y1) * (cy - y1);
			d1bool = d1 > r * r ? false : true;
			d2 = (cx - x2) * (cx - x2) + (cy - y2) * (cy - y2);
			d2bool = d2 > r * r ? false : true;
			if (d1bool != d2bool)ans++;
		}
		cout << ans << "\n";
	}
}
