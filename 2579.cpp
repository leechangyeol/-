#include <iostream>

using namespace std;

#define MAX 300

int dp[MAX];
int num[MAX];

int main(void) {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> num[i];

	dp[0] = num[0];
	dp[1] = num[0] + num[1];
	dp[2] = num[0] + num[2] > num[1] + num[2] ? num[0] + num[2] : num[1] + num[2];
	for (int i = 3; i < n; i++) {
		dp[i] = dp[i - 3] + num[i - 1] + num[i] > dp[i - 2]  + num[i] ?
			dp[i - 3] + num[i - 1] + num[i] : dp[i - 2]  + num[i];
	}

	cout << dp[n-1] << "\n";
}
