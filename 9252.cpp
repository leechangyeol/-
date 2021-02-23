#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 1001;
int dp[MAX][MAX];
int main(void) {
	string a, b;
	string ans;
	cin >> a >> b;
	int len_1 = a.size();
	int len_2 = b.size();
	for (int i = 1; i <= a.size(); i++) {
		for (int j = 1; j <= b.size(); j++) {
			dp[i][j] = max({ dp[i - 1][j],dp[i][j - 1],dp[i - 1][j - 1] + (a[i - 1] == b[j - 1]) });
		}
	}
	while (dp[len_1][len_2] != 0) {
		if (dp[len_1][len_2] == dp[len_1 - 1][len_2])
			len_1--;
		else if (dp[len_1][len_2] == dp[len_1][len_2 - 1])
			len_2--;
		else {
			len_1--, len_2--;
			ans += a[len_1];
		}
	}
	cout << dp[a.size()][b.size()] << "\n";
	for(int i = ans.size()-1;i>=0;i--)
		cout << ans[i];
}
