#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 251;
string dp[MAX];
int n;
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
int main(void) {
	
	dp[0] = dp[1] = "1";
	dp[2] = "3";
	for (int i = 3; i <= 250; i++) {
		dp[i] = bigAdd(bigAdd(dp[i - 2], dp[i - 2]), dp[i - 1]);
	}
	while (1)
	{
		cin >> n;
		if (cin.eof()) break;
		cout << dp[n] << "\n";
	}
}
