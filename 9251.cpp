#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 1001;
int dp[MAX][MAX];
int main(void) {
	string a, b;
	cin >> a >> b;
	for (int i = 1; i <= a.size(); i++) {
		for (int j = 1; j <= b.size(); j++) {
			dp[i][j] = max({ dp[i - 1][j],dp[i][j - 1],dp[i - 1][j - 1] + (a[i-1] == b[j-1]) });
		}
	}
	cout << dp[a.size()][b.size()];
}
