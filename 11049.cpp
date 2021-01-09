#include <iostream>
#include <algorithm>
#define MAX 501
#define INT_MAX 987654321

using namespace std;

pair<int, int> as[MAX];
int dp[MAX][MAX];
int n;

int sol(int x,int y) {
	if (x == y) return 0;

	int &ref = dp[x][y];
	if (ref != 0)return ref;

	int _min = INT_MAX;
	for (int i = x; i < y; i++)
		_min = min(_min, sol(x, i) + sol(i + 1, y) + as[x].first*as[i].second*as[y].second);
	return ref = _min;
}
int main(void) {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		as[i] = { a,b };
	}
	
	cout << sol(0, n - 1);
}
