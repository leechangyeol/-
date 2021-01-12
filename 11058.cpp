#include <iostream>
#include <algorithm>

#define MAX 101

using namespace std;

long long dp[MAX];
int n;
int main(void) {
	cin >> n;

	for (int i = 1; i < 7; i++) {
		dp[i] = i;
	}

	for (int i = 7; i < MAX; i++) {
		for (int j = 1; j < i - 2; j++)
			dp[i] = max(dp[i], max(dp[i - 1] + 1, dp[i - j - 2] * (j + 1)));
	}
	cout << dp[n];
}
