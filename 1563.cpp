#include <iostream>
#define MAX 1001
#define div 1000000
using namespace std;

int n;

int dp[MAX][2][3];

int sol(int day, int cnt1, int cnt2) {
	if (cnt1 >= 2 || cnt2 >= 3) {
		return 0;
	}
	if (day == n) return 1;

	int& ref = dp[day][cnt1][cnt2];
	if (ref != -1)return ref;
	return ref = (sol(day + 1, cnt1, 0) + sol(day + 1, cnt1 + 1, 0) + sol(day + 1, cnt1, cnt2 + 1)) % div;
}

int main(void) {
	cin >> n;
	memset(dp, -1, sizeof(dp));
	cout << sol(0, 0, 0);
}
