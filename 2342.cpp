#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 100001;
int value[MAX];
int n;
int dp[5][5][MAX];
int dfs(int left, int right, int i) {
	if (n == i) { return 0; }

	int& ret = dp[left][right][i];
	if (ret != -1)return ret;
	if (left == 0 && right == 0)return ret = dfs(value[i], right, i + 1) + 2;

	if (left == value[i])return ret = dfs(value[i], right, i + 1) + 1;
	else if (right == value[i])return ret = dfs(left, value[i], i + 1) + 1;

	int leftvalue, rightvalue;
	leftvalue = rightvalue = 0;

	if (left == 0)leftvalue = dfs(value[i], right, i + 1) + 2;
	else if (abs(left - value[i]) == 2) leftvalue = dfs(value[i], right, i + 1) + 4;
	else leftvalue = dfs(value[i], right, i + 1) + 3;


	if (right == 0)rightvalue = dfs(left, value[i], i + 1) + 2;
	else if (abs(right - value[i]) == 2)rightvalue = dfs(left, value[i], i + 1) + 4;
	else rightvalue = dfs(left, value[i], i + 1) + 3;

	return ret = min(leftvalue, rightvalue);
}
int main(void) {

	memset(dp, -1, sizeof(dp));
	int a;
	while (1) {
		cin >> a;
		if (a == 0)break;
		value[n++] = a;
	}
	cout << dfs(0, 0, 0);
}
