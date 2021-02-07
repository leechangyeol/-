#include <iostream>
#include <vector>
using namespace std;
int n;
vector<pair<int, int>> pos;
double ccw(double x1, double y1, double x2, double y2, double x3, double y3) {
	return (x1 * y2 + x2 * y3 + x3 * y1 - (x2 * y1 + x3 * y2 + x1 * y3)) / 2;
}
int main(void) {
	cin >> n;
	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		pos.push_back({ x,y });
	}
	x = pos[0].first;
	y = pos[0].second;
	double ans = 0;
	for (int i = 1; i < pos.size()-1; i++) {
		ans += ccw(x, y, (double)pos[i].first, (double)pos[i].second, pos[i + 1].first, 
			(double)pos[i + 1].second);
	}
	cout << fixed;
	cout.precision(1);
	if (ans < 0)cout << -ans;
	else cout << ans;
}
