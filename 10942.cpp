#include <iostream>
using namespace std;
int n;
const int MAX = 2001;
int list[MAX];
bool dp[MAX][MAX];
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> list[i];
		for (int j = 1; j <= i; j++) {
			if (j == i)dp[j][i] = true;
			else if (i - j == 1)dp[j][i] = (list[j] == list[i]);
			else {
				dp[j][i] = dp[j + 1][i - 1] && (list[j] == list[i]);
			}
		}
	}
	cin >> n;
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		cout << dp[a][b] << "\n";
	}
}
