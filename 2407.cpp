#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 101;
string dp[MAX][MAX];
int n,m;
string bigAdd(string a, string b) {
	string temp;
	int sum ;
	int length_a, length_b, length_temp;
	sum = length_temp = 0;
	length_a = a.length() - 1;
	length_b = b.length() - 1;
	while (1) {
		if (length_a < 0 && length_b < 0 && sum <= 0)break;
		if (length_a >= 0) sum += a[length_a--] - '0';
		if (length_b >= 0) sum += b[length_b--] - '0';
		temp.push_back((sum%10) + '0');
		sum /= 10;
	}
	reverse(temp.begin(), temp.end());
	return temp;
}
string dfs(int a, int b) {
	if (a == b || a == 1 || b == 0) return "1";
	if (dp[a][b] != "")return dp[a][b];
	dp[a][b] = bigAdd(dfs(a - 1, b - 1), dfs(a - 1, b));
	return dp[a][b];
}
int main(void) {
	cin >> n >> m;
	cout << dfs(n, m);
}
